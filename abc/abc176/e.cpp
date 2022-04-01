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
using ll  = unsigned long long;
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
  int h,w,m;
  cin >> h >> w >> m;
  vp vh(h,P(0,0)),vw(w,P(0,0));
  vector<ll> vhw(m,0);
  rep(i,m) {
    ll a,b;
    cin >> a >> b;
    a--;b--;
    vh.at(a).fi++;
    vh.at(a).se = a;
    vw.at(b).fi++;
    vw.at(b).se = b;
    ll c = (a << 20) + b;
    vhw.at(i) = c;
  }
  sort(rng(vhw));
  sort(rrng(vh));
  sort(rrng(vw));

  int mxh = vh.at(0).fi,mxw=vw.at(0).fi;
  int isz = 0;
  vh.push_back(P(-1,-1));
  rep(k,vh.size()) {
    if(mxh!=vh.at(k).fi) {
      isz = k;
      break;
    }
  }
  int jsz = 0;
  vw.push_back(P(-1,-1));
  rep(k,vw.size()) {
    if(mxw!=vw.at(k).fi) {
      jsz = k;
      break;
    }
  }

  rep(i,isz) rep(j,jsz) {
    ll oi = vh.at(i).se;
    ll t = (oi << 20) + vw.at(j).se;
    auto low = lower_bound(rng(vhw),t);
    auto up = upper_bound(rng(vhw),t);
    if(!(up - low == 1)) {
      cout << vh.at(i).fi + vw.at(j).fi << endl;
      return 0;
    }
  }

  cout << vh.at(0).fi + vw.at(0).fi -1 << endl;

  return 0;
}
