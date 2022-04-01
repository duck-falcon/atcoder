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
  int n,m;
  cin >> n >> m;
  vector<int> a(n,0);
  int tot = 0;
  rep(i,n) {
    cin >> a.at(i);
    tot += a.at(i);
  }

  sort(all(a));
  reverse(all(a));
  bool flag = true;
  rep(i,m) {
    if(4*m*a.at(i) < tot) flag = false;
  }
  if(flag) cout <<"Yes" << endl;
  else cout << "No" <<endl;



  return 0;
}
