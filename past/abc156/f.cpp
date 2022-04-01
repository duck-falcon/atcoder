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
void pv(vector<P<int,int>> vec) {
  cout << "[";
  for(auto& v : vec) {
    cout << "<"
    cout << v.fi << ","<< v.se << ">";
    cout << ",";
  }
  cout << "]" << endl;
}

template<typename T>
void pv(vector<T> vec) {
  cout << "[";
  for(auto& v : vec) {
    cout << v << ",";
  }
  cout << "]" << endl;
}

int main() {


  return 0;
}
