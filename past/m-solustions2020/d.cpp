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
  int n;cin >> n;
  vl a(n,0);
  vi ud(n,10);
  rep(i,n) {
    cin >> a.at(i);
    if(i != 0) {
      if(a.at(i-1) < a.at(i)) ud.at(i-1) = 1;
      else if(a.at(i-1) > a.at(i)) ud.at(i-1) = -1;
      else ud.at(i-1) = 0;
    }
  }
  ud.at(n-1) = -1;


  ll ans = 0; ll kane = 1000;ll kabu = 0;

  bool p = false;
  ll mni = 0;
  rep(i,n) {
    if(ud.at(i) == 1 and !p) {
      p = true;
      kabu = kane / a.at(i);
      kane = kane % a.at(i);
      mni = i;
    }
    if(ud.at(i) == -1 and p) {
      p = false;
      kane += kabu * a.at(i);
      kabu = 0;
    }
  }

  cout << kane << endl;

  return 0;
}
