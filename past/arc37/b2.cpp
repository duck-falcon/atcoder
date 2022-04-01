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

template<typename T> void pv(vector<T> vec) {
  cout << "[";
  for(auto& v : vec) { cout << v << ","; }
  cout << "]" << endl;
}

template<typename T> void pv2(vector<vector<T>> vec) {
  for(auto& v : vec) pv(v);
}

// dfs-tree

int n;
vvi maze;
vi seen;
bool flag;

bool dfs(int x, int before) {
  int sz = maze.at(x).size();
  seen.at(x) = 1;
  rep(i,sz) {
    int nx = maze.at(x).at(i);
    if(nx == before) continue;
    if(!seen.at(nx)) dfs(nx, x);
    else flag = false;
  }
  return flag;
}

// 入力整形例
int main() {
  cin >> n;
  maze = vvi(n,vi());
  seen = vi(n,0);
  int m;cin >> m;
  rep(i,m) {
    int a,b;cin >> a >> b;
    a--;b--;
    maze.at(a).eb(b);
    maze.at(b).eb(a);
  }

  int ans = 0;
  rep(i,n) {
    if(!seen.at(i)) {
      flag = true;
      ans += dfs(i,-1);
    }
  }

  cout << ans << endl;

  return 0;
}
