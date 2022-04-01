#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n) ; ++i)
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rng(x) (x).begin(),(x).end()
#define fi first
#define se second
#define emb emplace_back
#define fcout cout << fixed << setprecision(15)

using namespace std;
using ll = long long;
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

int dp[3001][3001];

int main() {
  string s,t;
  cin >> s >> t;

  int ns = s.size();
  int nt = t.size();

  rep(i,ns) rep(j,nt) {
    if(s.at(i)==t.at(j))  dp[i+1][j+1] = dp[i][j] + 1;
    else dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
  }

  int i = ns,j=nt;
  string ans = "";
  while(i+j) {
    if(j && dp[i][j-1] == dp[i][j]) j--;
    else if(i && dp[i-1][j] == dp[i][j]) i--;
    else {
      i--;j--;
      ans += s[i];
    }
  }
  reverse(rng(ans));
  cout << ans << endl;

  return 0;
}
