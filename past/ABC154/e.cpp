#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n) ; ++i)
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define all(x) x.begin(),x.end()

using namespace std;
using ll = long long;
using P = pair<int,int>;

template<typename T>
void printVec(vector<T> vec) {
  cout << "[";
  for(auto& v : vec) {
    cout << v << ",";
  }
  cout << "]" << endl;
}

int main() {
  string n;
  int K;
  cin >> n >> K;
  int l = n.length();

  int dp[101][4][2];
  rep(i,101) rep(j,K+1) rep(k,2) dp[i][j][k] = 0;
  dp[0][0][0] = 1;
  rep(i,l) rep(j,K+1) rep(k,2) {
    int nd = n[i]-'0';
    rep(d,10) {
      int nj=j,nk=k;
      if(d!=0) nj++;
      if(nj > K) continue;
      if(nk==0 and d > nd) continue;
      if(nk==0 and d < nd) nk++;
      dp[i+1][nj][nk] += dp[i][j][k];
    }
  }
  cout << dp[l][K][0] + dp[l][K][1] << endl;

  return 0;
}
