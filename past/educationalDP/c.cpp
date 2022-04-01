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
using P = pair<int,int>;
using vi = vector<int>;

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

ll dp[3][100005];
int main() {
  int n;
  cin >> n;
  vi a(n),b(n),c(n);
  rep(i,n) {
    cin >> a.at(i) >> b.at(i) >> c.at(i);
  }

  rep(i,n) {
    dp[0][i+1] = max(dp[1][i],dp[2][i]) + a.at(i);
    dp[1][i+1] = max(dp[0][i],dp[2][i]) + b.at(i);
    dp[2][i+1] = max(dp[0][i],dp[1][i]) + c.at(i);
  }

  ll res = 0;
  res = max(res,dp[0][n]);
  res = max(res,dp[1][n]);
  res = max(res,dp[2][n]);
  cout << res << endl;

  return 0;
}
