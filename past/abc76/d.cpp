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

double dp[105][105];
int n;
vi t(102);
vi v(102);

double d(int i,int k,int j) {
  int tt = t.at(i+1)-t.at(i);
  double S;
  double vv=(double)v.at(i+1);
  if(dp[i][k] == 0 and !(i==0 and k==0)) return 0;
  if(vv<j) return 0;
  if(abs(j-k)>tt) return 0;
  if(k>vv) return 0;
  if(2*vv-(k+j)<=tt) {

    S = ((vv-k)*(vv+k)+(vv-j)*(vv+j))/2.0 + vv*(tt-(vv-k)-(vv-j));
  } else {
    double a = (tt+(j-k))/2.0;
    S = a*k+(a*a)/2.0+((a-j+k)*(a-j+k))/2.0+j*(a-j+k);
  }
  return S+dp[i][k];
}

int main() {
  cin >> n;
  int sum = 0;
  orep(i,n) {
    int tmp;
    cin >> tmp;
    sum+=tmp;
    t.at(i) = sum;
  }
  orep(i,n) cin >> v.at(i);

  rep(i,n) rep(j,101) {
    rep(k,101) dp[i+1][j] = max(dp[i+1][j],d(i,k,j));
  }

  fcout << dp[n][0] << endl;

  return 0;
}
