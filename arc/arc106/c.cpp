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

const ll MX = 100100101;
int main() {
  int n,m;cin >> n >> m;
  if(m>0) {
    if(n-2<m) {
      cout << -1 << endl;
      return 0;
    }
    orep(i,m+1) {
      cout << 2*i << " " << 2*i+1<< endl;
    }
    int mx = 2*(m+2);
    cout << 1 << " " << mx << endl;
    rep(i,n-m-2) {
      cout << mx + 2*i +1 << " " << mx+2*i+2 << endl;
    }
    return 0;
  } else if(m == 0) {
    orep(i,n) {
      cout << 2*i << " " << 2*i+1<< endl;
    }
    return 0;
  } else {
    cout << -1 << endl;
  }

  return 0;
}
