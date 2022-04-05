#include <bits/stdc++.h>
#define rep(i,n)    for(long long i = 0; i < (n) ; ++i)
#define orep(i,n)   for(long long i = 1; i <= (n); ++i)   // one rep
#define drep(i,n)   for(long long i = (n)-1; i >= 0; --i) // down rep
#define srep(i,s,t) for(long long i = (s); i < (t); ++i)  // set rep
#define rng(x)  (x).begin(),(x).end()

  // range
#define rrng(a) (a).rbegin(),(a).rend() // reverse range
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define ru(x,y) (((x)+(y)-1)/(y)) // round up
#define fi first
#define se second
#define eb emplace_back
#define fcout cout << fixed << setprecision(15)


using namespace std;
using ll  = long long;
using P   = pair<int,int>;
using vi  = vector<int>;
using vvi = vector<vi>;
using vp  = vector<P>;
using vl  = vector<ll>;

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

template<typename T> void pv2(vector<vector<T>> vec) {
  for(auto& v : vec) pv(v);
}


int dp[2000][901];
int main() {
  int r,g,b;
  cin >> r >> g >> b;

  auto f = [&] (int ii,int jj) -> int {
    int iro;
    // red
    if(jj <= r) iro = 900;
    // green
    else if (jj <= r + g) iro = 1000;
    // blue
    else iro = 1100;
    return abs(iro-ii);
  };

  //　最初はは石を置けない
  orep(i,900) dp[0][i] = 1000000000;
  // 場所 r:900,g:1000,b:1100 左端:0 右端:2000
  orep(i,1999) {
    // 今までに何個置いたか
    orep(j,r+g+b) {
      dp[i][j] = min(dp[i-1][j-1] + f(i,j), dp[i-1][j]);
      //else dp[i][j] = dp[i-1][j];
    }
  }

  /*int ans = 1000000000;
  orep(i,1999) {
    ans = min(ans,dp[i][r+g+b]);
  }*/
  cout << dp[1999][r+g+b] << endl;

  return 0;
}
