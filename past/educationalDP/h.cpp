#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n) ; ++i)
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define emb emplace_back
#define fcout cout << fixed << setprecision(15)

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using P = pair<int,int>;

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

int dp[1005][1005];
const int mod = 1000000007;
int main() {
  int h,w;
  cin >> h >> w;
  vvi maze(h+1,vi(w+1,0));
  rep(i,h) rep(j,w) {
    char a;
    cin >> a;
    if(a=='.') maze[i][j] = 1;
    else maze[i][j] = 0;
  }

  dp[0][0] = 1;
  rep(i,h) rep(j,w) {
    if(maze[i][j+1]) {
      dp[i][j+1] += dp[i][j];
      dp[i][j+1] = dp[i][j+1] % mod;
    }
    if(maze[i+1][j]) {
      dp[i+1][j] += dp[i][j];
      dp[i+1][j] = dp[i+1][j] % mod;
    }
  }

  cout << dp[h-1][w-1] << endl;



  return 0;
}
