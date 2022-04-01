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
  string s,r;
  cin >> s;
  int n = s.length();
  r = s;
  reverse(all(r));
  if(r != s) {
    cout << "No" << endl;
    return 0;
  }
    string f,b;
    f = s.substr(0,(n-1)/2);
    b = s.substr((n+1)/2,(n-1)/2);
    string fr = f;
    reverse(all(fr));
    string br = b;
    reverse(all(br));
    if(fr != f) {
      cout << "No" << endl;
      return 0;
    }
    if(br != br)
    {
      cout << "No" << endl;
      return 0;
}

cout << "Yes" << endl;
  return 0;
}
