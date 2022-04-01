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
  int n;
  cin >> n;
  vector<int> p(n,0);
  rep(i,n) {
    cin >> p.at(i);
  }
  int ans = 1;int mn=p.at(0);
  rep(i,n-1) {
    if(mn >= p.at(i+1)) ans++;
    mn = min(mn,p.at(i+1));
  }
  cout << ans << endl;



  return 0;
}
