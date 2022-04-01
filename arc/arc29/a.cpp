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

int INF = 1001001001;
int main() {
  int n;
  cin >> n;
  vector<int> t(n,0);
  rep(i,n) cin >> t.at(i);

  int x,y;
  int res = INF;
  rep(i,1 << n) {
    x = 0;y = 0;
    rep(j,n) {
      if(i>>j&1) x += t.at(j);
      else y += t.at(j);
    }
    res = min(res,max(x,y));
  }

  cout << res << endl;

  return 0;
}
