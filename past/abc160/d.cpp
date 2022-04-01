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
  int n,x,y;
  cin >> n >> x >> y;

  vector<int> ans(n,0);
  rep(i,n) {
    FOR(j,i+1,n) {
      int temp = min(abs(j+1-y)+abs(i+1-x)+1,j-i);
      ans.at(temp) += 1;
    }
  }
  rep(i,n) {
    if(i==0) continue;
    cout << ans.at(i) << endl;
  }
  return 0;
}
