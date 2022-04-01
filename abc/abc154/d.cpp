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
  int n,k;
  cin >> n >> k;
  vector<int> p(n,0);
  rep(i,n) cin >> p[i];

  int max = 0;
  rep(i,k) max += p[i];
  int tmp = max;
  int ii = k;
  FOR(i,k,n) {
    tmp = tmp - p[i-k] + p[i];
    if(max < tmp) {
      max = tmp;
      ii = i;
    }
  }

  ll sum = 0;
  if (ii == k) {
    rep(i,k) {
      sum += p[i] + 1;
    }
  } else {
    FOR(i,ii-k+1,ii+1) {
      sum += (p[i] + 1);
    }
  }
  double ans = sum / 2.0;

  cout << fixed;
  cout << setprecision(14) << ans << endl;
  return 0;
}
