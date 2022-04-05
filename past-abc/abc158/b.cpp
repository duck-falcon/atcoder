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

int main() {
  ll a,b,n;
  cin >> n >> a >> b;
  if(a==0) {
    cout << 0 << endl;
    return 0;
  }
  ll r = n % (a + b);
  ll q = (n - r) / (a+b);
  ll ans = q * a;
  if(a <= r) ans += a;
  else ans += r;

  cout << ans << endl;

  return 0;
}
