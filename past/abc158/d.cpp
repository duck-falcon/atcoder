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
  string s;
  cin >> s;
  int q;
  cin >> q;
  int rev = 0;
  string mae = "",usiro = "";
  rep(i,q) {
    int t;
    cin >> t;
    if(t == 1) {
      rev += 1;
    } else {
      int f;string c;
      cin >> f >> c;
      if(rev % 2 == 1) {
        if(f == 1) {
          usiro += c;
        } else {
          mae.insert(0,c);
        }
      } else {
        if(f == 1) {
          mae.insert(0,c);
        } else {
          usiro += c;
        }
      }
    }
  }
  s = mae + s + usiro;
  if (rev % 2 == 1) reverse(all(s));
  cout << s << endl;

  return 0;
}
