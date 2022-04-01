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
  map<string,int> mp;

  rep(i,n) {
    string s="";
    cin >> s;
    mp[s]++;
  }

  int ma = 1;
  for(auto v : mp) ma = max(ma,v.second);
  for(auto v : mp) if (v.second == ma) cout << v.first << endl;

  return 0;
}
