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

template<typename T> void Yes(T flag) {
  cout << (flag ? "Yes" : "No") << endl;
}

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
  int c[3][3];
  rep(i,3) rep(j,3) cin >> c[i][j];

  int p = c[0][1] - c[0][0];
  if(p != c[1][1] - c[1][0]) {
    Yes(false);
    return 0;
  }
  if(p != c[2][1] - c[2][0]) {
    Yes(false);
    return 0;
  }

  int q = c[0][2] - c[0][1];
  if(q != c[1][2] - c[1][1]) {
    Yes(false);
    return 0;
  }
  if(q != c[2][2] - c[2][1]) {
    Yes(false);
    return 0;
  }

  int r = c[0][0] - c[0][2];
  if(r != c[1][0] - c[1][2]) {
    Yes(false);
    return 0;
  }
  if(r != c[2][0] - c[2][2]) {
    Yes(false);
    return 0;
  }

  if(0!=p+q+r) {
    Yes(false);
    return 0;
  }

  Yes(true);

  return 0;
}
