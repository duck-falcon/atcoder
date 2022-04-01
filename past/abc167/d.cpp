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
  ll n,k;
  cin >> n >> k;
  vp a(n+1,P(0,0));
  rep(i,n) {
    int b;
    cin >> b;
    a.at(i+1) = P(b,0);
  }
  ll loop=0;
  int here = 1;
  a.at(1).se = 1;
  rep(i,n) {
    here = a.at(here).fi;
    k--;
    if(k==0) {
      cout << here << endl;
      return 0;
    }
    if(a.at(here).se) break;
    a.at(here).se=1;
  }
  rep(i,n+1) a.at(i).se=0;
  a.at(here).se=1;
  rep(i,n) {
    here = a.at(here).fi;
    loop++;
    if(a.at(here).se) break;
  }
  rep(i,k%loop) {
    here = a.at(here).fi;
  }
  cout << here << endl;




  return 0;
}
