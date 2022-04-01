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

ll f(ll x,ll m) {
  return x % m;
}

int main() {
  ll n,x,m;
  cin >> n >> x >> m;

  vector<int> seen(m+5,0);
  vector<ll> sm(m+5,0);
  seen.at(x) = 1;
  sm.at(1) = x;

  ll loop = 1;
  ll tmpsm = x;
  bool loopflag=false;

  orep(i,n-1) {
    x = f(x*x,m);
    cout << x << endl;
    if(seen.at(x)) {
      loopflag=true;
      sm.at(i) = tmpsm;
      break;
    } else {
      loop+=1;
      tmpsm+=x;
      sm.at(i+1) = tmpsm;
      if(!(seen.at(x) == 0 or seen.at(x) == 1)) seen.at(x) = i+1;
    }
  }
  cout << "---------" << endl;
  cout << loop << endl;
  cout << x << endl;
  cout << seen.at(x) << endl;
  cout << "---------" << endl;

  ll loopsm = loopflag ? sm.at(loop) - sm.at(seen.at(x)) : sm.at(loop);
  ll beforesm = seen.at(x) != 1 ? sm.at(seen.at(x)-1) : 0;
  ll aftersm = loopflag ? sm.at(seen.at(x)-1 + n % loop) - sm.at(seen.at(x)-1) : 0;

  cout << loopsm << endl;
  cout << beforesm << endl;
  cout << aftersm << endl;

  cout << loopsm * (n / loop) + beforesm + aftersm << endl;

  return 0;
}
