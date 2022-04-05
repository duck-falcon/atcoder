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
  vector<int> a(9,0);
  vector<bool> c(9,false);
  rep(i,9) cin >> a.at(i);
  int n;
  cin >> n;
  vector<int> b(n,0);
  rep(i,n) {
    cin >> b.at(i);
    rep(j,9) {
      if(b.at(i) == a.at(j)) c.at(j) = true;
    }
  }

  if(c.at(0) && c.at(1) && c.at(2)) cout << "Yes" << endl;
  else if(c.at(3) && c.at(4) && c.at(5)) cout << "Yes" << endl;
  else if(c.at(6) && c.at(7) && c.at(8)) cout << "Yes" << endl;
  else if(c.at(0) && c.at(3) && c.at(6)) cout << "Yes" << endl;
  else if(c.at(1) && c.at(4) && c.at(7)) cout << "Yes" << endl;
  else if(c.at(2) && c.at(5) && c.at(8)) cout << "Yes" << endl;
  else if(c.at(0) && c.at(4) && c.at(8)) cout << "Yes" << endl;
  else if(c.at(2) && c.at(4) && c.at(6)) cout << "Yes" << endl;
  else cout << "No" << endl;



  return 0;
}
