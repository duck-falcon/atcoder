#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n) ; ++i)
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define emb emblace_back

using namespace std;
using ll = long long;
using P = pair<int,int>;

template<typename T>
void pv(vector<T> vec) {
  cout << "[";
  for(auto& v : vec) {
    cout << v << ",";
  }
  cout << "]" << endl;
}

int main() {
  ll n,k;
  cin >> n >> k;
  ll t=k;
  int m=1;
  while(t <= n) {
    t *= k;
    m++;
  }
  cout << m << endl;

  return 0;
}
