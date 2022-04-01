#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n) ; ++i)
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define all(x) (x).begin(),(x).end()
#define orep(i,n) for(long long i = 1;i<(n);++i)
#define drep(i,n) for(long long i=n;i>=0;--i)
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

const int mx = 100008;
ll INF = 1e18l;
// dp[v]=min(w)
ll dp[mx];

int main() {
  int n,w;
  cin >> n >> w;

  orep(i,mx) dp[i] = INF;

  rep(i,n) {
    int wi,vi;
    cin >> wi >> vi;
    drep(j,mx-vi) {
      dp[j+vi] = min(dp[j+vi],dp[j]+wi);
    }
  }

  int res=0;
  rep(i,mx) if(dp[i] <= w) res = max(res,i);
  cout << res << endl;

  return 0;
}
