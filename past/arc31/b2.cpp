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

int rows,columns;
// 4方向
vi dx = {1,0,-1,0}, dy = {0,1,0,-1};
// 8方向
// vi dx = {1,1,0,-1,-1,-1,0,1}, dy = {0,1,1,1,0,-1,-1,-1};

void dfs(vvi &maze, int x, int y) {
  int n = dx.size();
  maze.at(x).at(y) = 0;
  rep(i,n) {
    int nx = x + dx.at(i), ny = y + dy.at(i);
    if(isin(nx,0,columns) and isin(ny,0,rows) and maze.at(nx).at(ny)) dfs(maze,nx,ny);
  }
}

int main() {
  columns = 10,rows = 10;
  vvi maze(columns,vi(rows,0));
  rep(i, columns) {
    string s; cin >> s;
    rep(j, rows) maze.at(i).at(j) = s.at(j)=='o' ? 1 : 0;
  }
  // pv2(maze);

  rep(k,10) rep(l,10) {
    int num = 0;
    vvi tmp = maze;
    if(tmp.at(k).at(l)) continue;
    tmp.at(k).at(l) = 1;
    rep(i,10) rep(j,10) if(tmp.at(i).at(j)) {
      dfs(tmp, i, j);
      num++;
    }
    if(num == 1) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;

  return 0;
}
