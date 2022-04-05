#include <bits/stdc++.h>
#define rep(i,n) for(long long  i = 0; i < (n) ; ++i)
#define FOR(i,a,b) for(long long  i = (a); i < (b); ++i)
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

template<typename T>
void printVec(vector<T> vec) {
  cout << "[";
  for(auto& v : vec) {
    cout << v << ",";
  }
  cout << "]" << endl;
}

int main() {
  int n,K;
  cin >> n >> K;
  vector<ll> a(n,0);
  rep(i,n) cin >> a.at(i);

  sort(all(a));
  int mt = 0,zt=0,pt=0;
  mt = lower_bound(all(a),0) - a.begin();
  zt = count(all(a),0);
  pt = n- mt - zt;

  ll nm = mt * pt;
  ll nz = zt * (mt + pt) + zt * (zt-1)/2;
  ll np = mt * (mt - 1) /2 + pt * (pt - 1) /2;

  vector<ll> b(n*(n-1)/2,0);
  int k=0;
  if(nm >= K) {
    rep(i,mt) {
      FOR(j,mt+zt,n) {
        b.at(k) = a.at(i)*a.at(j);
        k++;
      }
    }
    sort(all(b));
    cout << b.at(K-1) << endl;
  } else if (nm+nz >= K) {
    cout << 0 << endl;
  } else {
    rep(i,mt) FOR(j,i+1,mt) {
      b.at(k) = a.at(i) * a.at(j);
      k++;
    }
    FOR(i,mt+zt,n) {
      FOR(j,i+1,n) {
        b.at(k) = a.at(i) * a.at(j);
        k++;
      }
    }
    sort(all(b));
    cout << b.at(K-1) << endl;
  }

  return 0;
}
