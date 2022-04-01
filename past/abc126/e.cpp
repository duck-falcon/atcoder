#include <bits/stdc++.h>
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


using namespace std;
using ll  = long long;
using P   = pair<int,int>;
using vi  = vector<int>;
using vvi = vector<vi>;
using vp  = vector<P>;
using vl  = vector<ll>;

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

const int INF = 100100101;

void dfsLength(int x, int length) {
  int sz = maze.at(x).size();
  seen.at(x) = 1;
  d.at(x) = min(d.at(x),length);
  rep(i,sz) {
    int nx = maze.at(x).at(i);
    if(!seen.at(nx)) dfsLength(nx,length+1);
  }
}

void dfs(int x) {
  int sz = maze.at(x).size();
  seen.at(x) = 1;
  rep(i,sz) {
    int nx = maze.at(x).at(i);
    if(!seen.at(nx)) dfs(nx);
  }
}

int main() {

  cin >> vertices;
  cin >> sides;

  maze = vvi(vertices,vi());
  seen = vi(vertices,0);
  rep(i,sides) {
    int a,b,c;cin >> a >> b >> c;
    a--;b--;
    maze.at(a).eb(b);
    maze.at(b).eb(a);
  }

  // つながっている頂点グループの数
  int ans = 0;
  rep(i,vertices) {
    if(!seen.at(i)) {
      dfs(i);
      ans++;
    }
  }

  cout << ans << endl;

  // start からの最短距離を全部求める
  /*int start = 3;
  d = vi(vertices,INF);
  dfsLength(start,0);*/

  return 0;
}
