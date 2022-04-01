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

int h,w;
int dp[101][101];
const int INF=1001001001;

int main() {
  cin >> h >> w;
  vvi maze(h+1,vi(w+1,-1));
  rep(i,h) rep(j,w) {
    char c;
    cin >> c;
    if(c=='.') maze.at(i).at(j) = 1;
    else maze.at(i).at(j) = 0;
  }

  rep(i,h) rep(j,w)  {
    dp[i][j] = INF;
  }
  if(maze[0][0]==0) dp[0][0] = 1;
  else dp[0][0] = 0;
  rep(i,h) rep(j,w) {
    if(maze.at(i).at(j)==1 and maze.at(i+1).at(j) == 0) dp[i+1][j] = min(dp[i+1][j],dp[i][j]+1);
    else dp[i+1][j] = min(dp[i+1][j],dp[i][j]);
    if(maze.at(i).at(j)==1 and maze.at(i).at(j+1) == 0) dp[i][j+1] = min(dp[i][j+1],dp[i][j]+1);
    else dp[i][j+1] = min(dp[i][j+1],dp[i][j]);
  }

  cout << dp[h-1][w-1] << endl;



  return 0;
}
