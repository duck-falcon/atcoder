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
  int n,s;
  int mod = 998244353;
  cin >> n >> s;
  vector<int> a(n+1,0);
  FOR(i,1,n+1) cin >> a.at(i);

  int sum = 0;
  FOR(L,1,n+1) {
    cout << "L" << endl;
    cout << L << endl;
    int tmp = a.at(L);
    if(tmp == s) {
      cout << "1つ " << endl;
      sum += (L)*(n-L+1);
      cout << (L)*(n-L+1) << endl;
      sum %= mod;
      continue;
    }
    FOR(R,L+1,n+1) {
      cout << "R" << endl;
      cout << R << endl;
      tmp += a.at(R);
      if(tmp == s) {
        cout << "いっぱい " << endl;
        sum += (L)*(n-R+1);
        cout << (L)*(n-R+1) << endl;
        sum %= mod;
        continue;
      }
    }
  }
  cout << sum << endl;

  return 0;
}
