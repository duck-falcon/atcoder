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

vvi maze(1005,vi(1005,0));
vi ans(3,0);
int h,w;
vi dx={1,1,0,-1,-1,-1,0,1},dy={0,1,1,1,0,-1,-1,-1};
int math=0;

void dfs(int x,int y) {
  maze.at(x).at(y)=0;
  math++;
  rep(i,8) {
    int nx=x+dx.at(i);int ny=y+dy.at(i);
    if(isin(nx,0,h) and isin(ny,0,w) and maze.at(nx).at(ny)) {
      dfs(nx,ny);
    }
  }
  return;
}

vi heihou(155);
int mx=150;
bool check(int a) {
  orep(i,mx) {
    if(a==heihou.at(i)) return true;
  }
  return false;
}

int abc(int r) {
  if(r%12==0) {
    int a = r/12;
    if(check(a)) return 0;
  }
  if(r%11==0) {
    int c = r/11;
    if(check(c)) return 2;
  }
  return 1;
}

int main() {
  orep(i,mx) {
    heihou.at(i) = (i*i);
  }
  cin >> h >> w;
  rep(i,h) rep(j,w) {
    char c;cin >> c;
    if(c=='o') maze.at(i).at(j) = 1;
  }

  rep(i,h) rep(j,w) {
    if(maze.at(i).at(j)) {
      math=0;
      dfs(i,j);
      ans.at(abc(math))++;
    }
  }

  cout << ans.at(0) << " " << ans.at(1) << " " << ans.at(2) << endl;

  return 0;
}
