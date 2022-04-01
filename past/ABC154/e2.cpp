#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n) ; ++i)
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define all(x) x.begin(),x.end()

using namespace std;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;

template<typename T>
void printVec(vector<T> vec) {
  cout << "[";
  for(auto& v : vec) {
    cout << v << ",";
  }
  cout << "]" << endl;
}

int f(int xx,int jj) {
  if(xx!=0) return jj+1;
  return jj;
}

//場所 未満フラグ 条件達成個数
int dp[105][2][105];
int main() {
  string s;
  int k;
  cin >> s >> k;
  int n = s.size();
  vi a(n,0);
  rep(i,n) a.at(i) = s.at(i) - '0';

  dp[0][0][0] = 1;
  rep(i,n) rep(j,2) rep(l,105) rep(x,j ? 10 : a.at(i) + 1) {
    dp[i+1][j or x < a.at(i)][f(x,l)] += dp[i][j][l];
  }

  cout << dp[n][1][k] + dp[n][0][k] << endl;

  return 0;
}
