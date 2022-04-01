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
  rep(i,n) cin >> a.at(i);

  bool flag = false;
  rep(i,n) {
    if(a.at(i)%2==0 and (a.at(i)%3!=0 and a.at(i)%5!=0)) flag = true;
  }
  if(flag) cout << "DENIED" << endl;
  else cout << "APPROVED" << endl;

  return 0;
}
