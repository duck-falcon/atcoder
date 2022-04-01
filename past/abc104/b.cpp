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
  string s;
  cin >> s;

  bool flag = true;
  if(s[0] != 'A') flag = false;
  string ss = s.substr(2,s.size()-3);
  int cnt = 0;
  rep(i,ss.size()) if(ss.at(i) == 'C') cnt++;
  if(cnt!=1)flag = false;
  rep(i,s.size()) {
    char c = s.at(i);
    if(c == 'A') continue;
    if(c == 'C') continue;
    if(isupper(c)) flag = false;
  }
  if(s.at(1) == 'C') flag = false;
  if(s.at(s.size()-1) == 'C') flag = false;
  if(flag) cout << "AC" << endl;
  else cout << "WA" << endl;

  return 0;
}
