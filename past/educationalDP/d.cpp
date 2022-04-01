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

ll dp[100005][102];

int main() {
int n,W;
cin >> n >> W;
vector<ll> w(n),v(n);
rep(i,n) cin >> w.at(i) >> v.at(i);

rep(wtot,W+1) rep(i,n) {
  dp[wtot][i+1] = max(dp[wtot][i+1],dp[wtot][i]);
  if(wtot+w.at(i) > W) continue;
  dp[wtot+w.at(i)][i+1] = max(dp[wtot+w.at(i)][i+1],dp[wtot][i]+v.at(i));
}

cout << dp[W][n] << endl;
  return 0;
}
