#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n) ; ++i)
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

template<typename T>
void printVec(vector<T> vec) {
  cout << "[";
  for(auto& v : vec) {
    cout << v << ",";
  }
  cout << "]" << endl;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n,0);
  rep(i,n) cin >> a[i];

  set<int> s(all(a));
  if(s.size() == n) cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;
}
