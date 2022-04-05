#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n) ; ++i)
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define emb emplace_back
#define fcout cout << fixed << setprecision(15)

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
  int k,n;
  cin >> k >> n;
  vector<int> a(n,0);

  int mx = 0;
  rep(i,n) {
    cin >> a.at(i);
  }

  rep(i,n-1) {
    mx = max(mx,abs(a.at(i)-a.at(i+1)));
  }
  mx = max(mx,k-abs(-a.at(0)+a.at(n-1)));
  cout << k - mx << endl;
  return 0;
}
