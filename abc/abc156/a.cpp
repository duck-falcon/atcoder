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
  int n,r;
  cin >> n >> r;

  if(n < 11) cout << r + 100*(10-n) << endl;
  else cout << r << endl;


  return 0;
}
