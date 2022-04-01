#include <bits/stdc++.h>
#define rep(i,n)    for(int i = 0; i < (n) ; ++i)
#define orep(i,n)   for(int i = 1; i <= (n); ++i)   // one rep
#define drep(i,n)   for(int i = (n)-1; i >= 0; --i) // down rep
#define srep(i,s,t) for(int i = (s); i < (t); ++i)  // set rep
#define rng(x)  (x).begin(),(x).end()   // range
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

ll dp[2005][2005];

int main() {
  int n;
  cin >> n;
  vp a(n);
  rep(i,n) {
    int t;
    cin >> t;
    a.at(i) = P(t,i);
  }
  sort(rrng(a));

  rep(j,n) dp[0][j+1] = dp[0][j] + a.at(j).fi * abs(n-a.at(j).se-j-1);
  rep(i,n) dp[i+1][0] = dp[i][0] + a.at(i).fi * abs(a.at(i).se-i);

  rep(i,n) rep(j,n) {
    if(i+j > n-1) continue;
    if(i==0) continue;
    ll u = a.at(i+j).fi;
    ll d = a.at(i+j).se;
    dp[i][j+1] = max(dp[i][j] + u * abs(n-d-j-1),dp[i-1][j+1]+u*abs(d-i+1));
  }

  ll res = 0;
  rep(i,n+1) {
    res = max(res,dp[i][n-i]);
  }

  cout << res << endl;

  return 0;
}
