#include <bits/stdc++.h>
using namespace std;
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

using ll  = long long;
using P   = pair<int,int>;
using vi  = vector<int>;
using vvi = vector<vi>;
using vp  = vector<P>;
using vvp = vector<vp>;
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

ll f(ll i,vi &sa,int n) {
  bool flag = true;
  ll ans = 0;

  rep(j,n) {
    if(i==2*j) {
      flag = false;
      ans += sa.at(2*j+1);
      continue;
    } else if(i==(2*j+1)) {
      flag = false;
      ans += sa.at(i-1)+sa.at(i);
      continue;
    }
    if(flag) ans += sa.at(2*j);
    else ans += sa.at(2*j+1);
  }

  return ans;
}

const ll INF=90000000000000004l;
int main() {
  int n,m;cin >> n >> m;
  vi h(n,0);
  vi w(m,0);

  rep(i,n) cin >> h.at(i);
  rep(i,m) cin >> w.at(i);

  sort(rng(w));
  sort(rng(h));

  vi sa(n-1,0);
  rep(i,n-1) {
    sa.at(i) = h.at(i+1) - h.at(i);
  }

  ll ans = INF;

  rep(i,n) {
    ll sum = f(i,sa,n/2);

    auto it = lower_bound(rng(w),h.at(i));
    int ff = it - w.begin();
    int x = w.at(ff);
    if(ff > 0) {
      int y = w.at(ff-1);
      cout << ff << endl;
      sum += min(abs(x-h.at(i)),abs(y-h.at(i)));
    }else {
      sum += abs(x-h.at(i));
    }

    ans = min(ans,sum);
  }

  cout << ans << endl;

  return 0;
}
