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

// 2方向
vi dx = {1,-1}, dy = {1,-1};
// 8方向
// vi dx = {1,1,0,-1,-1,-1,0,1}, dy = {0,1,1,1,0,-1,-1,-1};

// 行、列
int rows,columns;
// 長方形グリッド
vvi maze;
// 既に到達した点
vvi seen;
// ある地点からの最短距離
vvi d;
// start goal
int sx,sy,gx,gy;

ll ans = 0;
void dfs(int x, int y, int t) {
  int n = dx.size();
  rep(i,n) {
    int nx = t == 1 ? x + dx.at(i) : x, ny =  t == 2 ? y + dy.at(i) : y;
    if(isin(nx,0,columns) and isin(ny,0,rows) and maze.at(nx).at(ny)!=0 and seen.at(nx).at(ny)!=t) {
      if(seen.at(nx).at(ny) == 0) ans ++;
      seen.at(nx).at(ny) = t;
      dfs(nx,ny,t);
    }
  }
}

// 入力整形例
int main() {
  // h w のこと
  cin >> columns >> rows;
  maze = vvi(columns,vi(rows,2));
  seen = vvi(columns,vi(rows,0));
  int n,m;cin >> n >> m;
  rep(i, n) {
    int a,b;cin >> a >> b;
    a--;b--;
    maze.at(a).at(b) = 1;
  }

  rep(i, m) {
    int a,b;cin >> a >> b;
    a--;b--;
    maze.at(a).at(b) = 0;
  }
  rep(i,columns) {
    rep(j,rows) {
     if(maze.at(i).at(j)==1) {dfs(i,j,1);
     dfs(i,j,2);
   }
   }
 }
  cout << ans << endl;
  return 0;
}
