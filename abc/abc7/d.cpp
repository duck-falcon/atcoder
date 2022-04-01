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
using vi = vector<int>;

template<typename T> void Yes(T flag) {
  cout << (flag ? "Yes" : "No") << endl;
}

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

// 場所 未満フラグ 条件達成フラグ
ll dp[20][2][2];

bool f(int x) {
  if(x == 4 or x == 9) return true;
  return false;
}

// dp calc
ll calc(int n,vi &v,bool self) {
  rep(i,20) rep(j,2) rep(k,2) dp[i][j][k] = 0;
  dp[0][0][0] = 1;

  rep(i,n) rep(j,2) rep(k,2) rep(x,j ? 10 : v.at(i)+1) {
    dp[i+1][j || x < v.at(i)][k || f(x)] += dp[i][j][k];
  }
  if (self) return dp[n][0][1] + dp[n][1][1];
  return dp[n][1][1];
}

int main() {
  string a,b;
  cin >> a >> b;

  int na = a.size(),nb=b.size();
  vi va(na,0);
  rep(i,na) va.at(i) = a.at(i) - '0';
  vi vb(nb,0);
  rep(i,nb) vb.at(i) = b.at(i) - '0';

  cout << calc(nb,vb,true) - calc(na,va,false)  << endl;

  return 0;
}
