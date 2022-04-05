#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n) ; ++i)
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define emb emblace_back

using namespace std;
using ll = long long;
using P = pair<int,int>;

template<typename T>
void pv(vector<T> vec) {
  cout << "[";
  for(auto& v : vec) {
    cout << v << ",";
  }
  cout << "]" << endl;
}

int main() {
  int n;
  cin >> n;
  vector<int> x(n,0);
  rep(i,n) cin >> x.at(i);

  ll mn=1e18;
  rep(i,100) {
    ll d=0;
    rep(j,n) {
      d += (i - x.at(j)) * (i - x.at(j));
    }
    mn = min(mn,d);
  }
  cout << mn << endl;

  return 0;
}
