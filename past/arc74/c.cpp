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

ll f(ll h,ll w,ll i) {
  ll ans=100000001,ans2=100000001;
  ll ss = h*w;
  ll t = i * w;
  ll r = (h - i)*(w/2);
  ll s = ss - t - r;
  ans = min(ans,max(t,max(r,s))-min(t,min(r,s)));

  r = w*((h-i)/2);
  s = ss - t - r;
  ans2 = min(ans2,max(t,max(r,s))-min(t,min(r,s)));
  return min(ans,ans2);
}

int main() {
  ll h,w;
  cin >> h >> w;

  ll ans = 100000001;
  orep(i,h/2) ans=min(ans,f(h,w,i));
  swap(h,w);
  orep(i,h/2) ans=min(ans,f(h,w,i));
  cout << ans << endl;

  return 0;
}
