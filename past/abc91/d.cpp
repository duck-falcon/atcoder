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

int main() {
  int n; cin >> n;
  vl a(n,0),b(n,0);
  rep(i,n) cin >> a.at(i);
  rep(i,n) cin >> b.at(i);

  int two = 1;
  int ans = 0;
  rep(i,29) {
    vi ma(n,0),mb(n,0);
    rep(j,n) {
      ma.at(j) = a.at(j) % (two*2);
      mb.at(j) = b.at(j) % (two*2);
    }

    sort(rng(mb));
    ll oddeven=0;
    rep(j,n) {
      int l = two - ma.at(j),r = 2*two-1-ma.at(j);
      oddeven+=upper_bound(rng(mb),r)-lower_bound(rng(mb),l);
      int ll = two*3-ma.at(j),rr=two*4-1-ma.at(j);
      oddeven+=upper_bound(rng(mb),rr)-lower_bound(rng(mb),ll);
    }
    if(oddeven%2==1)ans+=two;
    two*=2;
  }
  cout << ans << endl;

  return 0;
}
