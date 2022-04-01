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

int dp[100005];
int INF = 1001001001;
int main() {
  int n;
  cin >> n;
  vector<int> h(n,0);
  rep(i,n) cin >> h.at(i);
  h.emb(INF);
  h.emb(INF);


  rep(i,n) dp[i] = INF;
  dp[0] = 0;

  rep(i,n) {
    dp[i+1] = min(dp[i+1],dp[i]+abs(h.at(i+1)-h.at(i)));
    dp[i+2] = min(dp[i+2],dp[i]+abs(h.at(i+2)-h.at(i)));
  }
  cout << dp[n-1] << endl;
  return 0;
}
