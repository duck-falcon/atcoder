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
  vector<string> s(n,"");
  rep(i,n) cin >> s.at(i);

  sort(all(s));
  int max = 1;
  int k = 0;
  int m = 0;
  vector<string> b(n,"a");
  rep(i,n) {
    m = upper_bound(all(s),s.at(i)) - (s.begin() + i);

    if(max < m) {
      max = m;
      k = 0;
      b.at(k) = s.at(i);
      k++;
    } else if(max == m) {
      b.at(k) = s.at(i);
      k++;
    }
  }
  rep(i,k) cout << b.at(i) << endl;

  return 0;
}
