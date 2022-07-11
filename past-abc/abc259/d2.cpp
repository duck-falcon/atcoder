#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)    for(long long i = 0; i < (n) ; ++i)
#define orep(i,n)   for(long long i = 1; i <= (n); ++i)   // one rep
#define drep(i,n)   for(long long i = (n)-1; i >= 0; --i) // down rep
#define srep(i,s,t) for(long long i = (s); i < (t); ++i)  // set rep
#define rng(x)  (x).begin(),(x).end() // range
#define rrng(a) (a).rbegin(),(a).rend() // reverse range
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define ru(x,y) (((x)+(y)-1)/(y)) // round up
#define fi first
#define se second
#define eb emplace_back
#define fcout cout << fixed << setprecision(15)

using ll  = long long;
using P   = pair<int,int>;
using vi  = vector<int>;
using vvi = vector<vi>;
using vp  = vector<P>;
using vvp = vector<vp>;
using vl  = vector<ll>;
using rpq = priority_queue<int,vi,less<int>>;   // 大きい順
using pq  = priority_queue<int,vi,greater<int>>;// 小さい順

template<typename T> void Yes(T flag) {
  cout << (flag ? "Yes" : "No") << endl;
}

template<typename T> void pv(vector<T> vec) {
  cout << "[";
  for(auto& v : vec) { cout << v << ","; }
  cout << "]" << endl;
}

template<>
void pv(vector<P> vec) {
  cout << "[";
  for(auto& v : vec) {
    cout << "<" << v.fi << ","<< v.se << ">" << ",";
  }
  cout << "]" << endl;
}

template<typename T> void pv2(vector<vector<T>> vec) {
  for(auto& v : vec) pv(v);
}



// dfs-tree

// 頂点数、辺数
int vertices,sides;
// グラフ
vvi maze;
// 既に到達した点
vi seen;
// ある地点からの最短距離,閉路を含まない場合のみ短時間で計算可能（木など）
vi d;

const int INF = 1001001011;
int s,t;

bool dfs(int x) {
  int sz = maze.at(x).size();
  seen.at(x) = 1;

  rep(i,sz) {
    int nx = maze.at(x).at(i);
    if(!seen.at(nx)) dfs(nx);
  }
  return false;
}

struct V{
  ll x,y;
  V(ll x = 0, ll y = 0) : x(x),y(y) {}

};

int main() {
  int n;cin >> n;

  V s,t;
  cin >> s.x >> s.y >> t.x >> t.y;

  vector<V> p(n+2);
  vl r(n+2,0);

  auto pow2 = [] (ll x){
    return x*x;
  };
  auto dist = [&] (V a, V b) {
    return pow2(a.x - b.x) + pow2(a.y - b.y);
  };

  // どの円に乗っているか
  rep(i, n) {
    cin >> p.at[i].x >> p.at[i].y >> r[i];
    if( dist(p, s) == pow2(r[i]) ) s = i;
    if( dist(p, t) == pow2(r[i]) ) t = i;
  }

  vertices = n;
  sides = n;

  maze = vvi(vertices,vi());
  seen = vi(vertices,0);
  rep(i, n) {
    srep(j, i+1, n) {
      if(p[i].x == p[j].x and p[i].y == p[j].y and r[i] != r[j] ) continue;
      if(dist(p[i], p[j])  <= pow2(r[i])) {
        maze.at(i).eb(j);
        maze.at(j).eb(i);
      }
    }
  }

  dfs(s);
  Yes(seen.at(t));
  return 0;
}
