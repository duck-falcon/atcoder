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

// dfs-tree

// 頂点数、辺数
int vertices,sides;
// グラフ
vvp maze;
// 既に到達した点
vp seen;
// ある地点からの最短距離,閉路を含まない場合のみ短時間で計算可能（木など）
vi d;

const int INF = 100100101;


void dfs(int x, int odd) {
  int sz = maze.at(x).size();
  seen.at(x).fi = 1;
  if(odd) seen.at(x).se = 1;
  rep(i,sz) {
    int nx = maze.at(x).at(i).fi;
    if(!seen.at(nx).fi) dfs(nx,(seen.at(x).se + maze.at(x).at(i).se) % 2);
  }
}

int main() {
  cin >> vertices;
  sides = vertices - 1;

  const int INF = 100100101;

  maze = vvp(vertices,vp());
  // fi seen ,se odd or even
  seen = vp(vertices,P(0,0));

  rep(i,sides) {
    int a,b,c;cin >> a >> b >> c;
    a--;b--;
    maze.at(a).eb(P(b,c%2));
    maze.at(b).eb(P(a,c%2));
  }

  rep(i,vertices) {
    if(!seen.at(i).fi) {
      dfs(i,0);
    }
  }

  rep(i,vertices) {
    cout << seen.at(i).se << endl;
  }

  return 0;
}
