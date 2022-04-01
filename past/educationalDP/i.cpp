#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n) ; ++i)
#define srep(i,a,b) for(int i = (a); i < (b); ++i)
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

double dp[3000][3000];

int main() {
  int n;
  cin >> n;
  vector<double> p(n,0);
  rep(i,n) cin >> p.at(i);

  dp[0][0] =1;
  rep(i,n) {
    rep(j,n+1) {
      if(j-1>=0) dp[i+1][j] += (dp[i][j-1] * p.at(i));
      dp[i+1][j] += (dp[i][j]*(1-p.at(i)));
    }
  }

  double ans=0;

  srep(i,n/2+1,n+1) {
      ans+=dp[n][i];
  }
  fcout << ans << endl;
  return 0;
}
