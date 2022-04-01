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

ll asum,bsum;
// dfs-tree

// 頂点数、辺数
int vertices,sides;
// グラフ
vvi maze;
// 既に到達した点
vi seen;
// ある地点からの最短距離,閉路を含まない場合のみ短時間で計算可能（木など）
vi d;
vl a,b;

void dfs(int x) {
  int sz = maze.at(x).size();
  seen.at(x) = 1;
  asum+=a.at(x);bsum+=b.at(x);
  rep(i,sz) {
    int nx = maze.at(x).at(i);
    if(!seen.at(nx)) dfs(nx);
  }
}

int main() {
  int vertices,sides;
  cin >> vertices;
  cin >> sides;
   a = vl(vertices,0),
   b= vl(vertices,0);
  rep(i,vertices) cin >> a.at(i);
  rep(i,vertices) cin >> b.at(i);

  maze = vvi(vertices,vi());
  seen = vi(vertices,0);
  rep(i,sides) {
    int c,d;cin >> c >> d;
    c--;d--;
    maze.at(c).eb(d);
    maze.at(d).eb(c);
  }

  bool flag=true;
  // つながっている頂点グループの数
  rep(i,vertices) {
    if(!seen.at(i)) {
      asum=0;bsum=0;
      dfs(i);
      if(asum!=bsum) flag=false;
    }
  }

  Yes(flag);

  return 0;
}
