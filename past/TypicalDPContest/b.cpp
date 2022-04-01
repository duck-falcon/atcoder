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

// first = x ,second = y
// dp[i][j] = a が i個, b が j個　のときそれ以降の x - y の最適
int dp[1005][1005];
const int INF = 100100101;
int main() {
  ll n,m;cin >> n >> m;
  vi a(n,0),b(m,0);
  rep(i,n) cin >> a.at(i);
  rep(i,m) cin >> b.at(i);

  reverse(rng(a));
  reverse(rng(b));

  int sm = 0;
  rep(i,n) sm += a.at(i);
  rep(i,m) sm += b.at(i);
  int sz = n + m;

  orep(len,sz) {
    rep(i,min(n+1,len+1)) {
      int j = len - i;
      if(j > m) continue;
    // first
      if((sz + len) % 2 == 0) {
        if(j - 1 < 0) dp[i][j] = dp[i - 1][j] + a.at(i-1);
        else if ( i - 1 < 0) dp[i][j] = dp[i][j-1] + b.at(j-1);
        else dp[i][j] = max(dp[i][j-1] + b.at(j-1),dp[i-1][j] + a.at(i-1));
      }
    // second
      else {
        if(j - 1 < 0) dp[i][j] = dp[i - 1][j] - a.at(i-1);
        else if ( i - 1 < 0) dp[i][j] = dp[i][j-1] - b.at(j-1);
        else dp[i][j] = min(dp[i][j-1] - b.at(j-1),dp[i-1][j] - a.at(i-1));
      }
    }
  }

  cout << (dp[n][m] + sm) / 2 << endl;

  return 0;
}
