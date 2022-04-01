#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n) ; ++i)
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define emb emplace_back

using namespace std;
using ll = long long;
using P = pair<int,int>;

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

ll gx=0,gd=0;
int main() {
  int n;
  cin >> n;
  ll ans = 1;
  ll count = 1;
  ll mod = 998244353;

  vector<P> xd(n,P(0,0));
  rep(i,n) {
    cin >> xd.at(i).fi >> xd.at(i).se;
  }
  sort(all(xd),[](P x, P d) -> int {
                        return ( x.fi < d.fi );
                        } );
  gx = xd.at(0).fi;
  gd = xd.at(0).se;
  FOR(i,1,n-1) {
    ll x,d;
    x = xd.at(i).fi;
    d = xd.at(i).se;
    if(gx+gd > x) count += 1;
    else {
      ans *= count;
      ans = ans % mod;
      count = 1;
    }
    if(gd-(x-gx) > d)gd = gd - x;
    else gd = d;
    gx = x;
  }

  ans *= count;
  ans = (ans+1) % mod;

  cout << ans << endl;

  return 0;
}
