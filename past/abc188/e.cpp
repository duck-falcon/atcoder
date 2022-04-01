#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)    for(long long i = 0; i < (n) ; ++i)
#define orep(i,n)   for(long long i = 1; i <= (n); ++i)   // one rep
#define drep(i,n)   for(long long i = (n)-1; i >= 0; --i) // down rep
#define srep(i,s,t) for(long long i = (s); i < (t); ++i)  // set rep
#define rng(x)  (x).begin(),(x).end()

  // range
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

ll INF = 100100101111;
ll minuss = -INF;ll pluss = -1;int cnt = 0;
vi a(200005,0);

void dfsLength(int x, int length) {
  int sz = maze.at(x).size();
  seen.at(x) = 1;
  d.at(x) = min(d.at(x),length);
  rep(i,sz) {
    int nx = maze.at(x).at(i);
    if(!seen.at(nx)) dfsLength(nx,length+1);
  }
}

void dfs(int x,ll now) {
  int sz = maze.at(x).size();
  if(sz==0) {
    pluss = max(pluss,now);
    return;
  }
  //seen.at(x) = 1;
  rep(i,sz) {
    int nx = maze.at(x).at(i);
    ll sa = a.at(nx)-a.at(x);
    if(sa >= 0) dfs(nx,now+sa);
    else {
      pluss = max(pluss,now);
      now = 0;
      minuss = max(minuss,sa);
      cnt++;
      dfs(nx,0l);
    }
  }
}


int main() {

  cin >> vertices;
  cin >> sides;
  vi t(vertices,1);
  rep(i,vertices) cin >> a.at(i);

  maze = vvi(vertices,vi());
  //seen = vi(vertices,0);
  rep(i,sides) {
    int aa,b;cin >> aa >> b;
    aa--;b--;
    t.at(b) = 0;
    maze.at(aa).eb(b);
  }

  rep(i,vertices) {
    if(t.at(i) == 1) dfs(i,0l);
  }
  if(cnt != sides) cout << pluss << endl;
  else cout << minuss << endl;

}
