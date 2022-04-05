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
  int n,m;
  cin >> n >> m;
  vector<int> s(m,0);
  vector<int> c(m,0);
  rep(i,m) cin >> s.at(i) >> c.at(i);
  rep(i,m){
    rep(j,m) {
      if(i == j) continue;
      if(s.at(i) == s.at(j) and c.at(i) != c.at(j)) {
        cout << "-1" << endl;
        return 0;
      }
    }
  }
  if(n==2 or n == 3) {
    rep(i,m) {
       if(s.at(i) == 1 and c.at(i) == 0) {
         cout << "-1" << endl;
         return 0;
       }
    }
  }

  vector<int> ans(n,0);
  rep(i,m) {
      ans.at(s.at(i)-1) = c.at(i);
  }


  if (ans.at(0) == 0 and n == 1) {
    cout << "0";
    return 0;
  }
  else if(ans.at(0) == 0) ans.at(0) = 1;
  rep(i,n) cout << ans.at(i);

  cout << endl;


  return 0;
}
