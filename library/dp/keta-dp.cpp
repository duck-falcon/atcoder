// 一般的な桁dp

const int keta = 100;
const int miflag = 2;
const int arflag = 2;
//桁 未満フラグ 条件達成フラグ
ll dp[keta][miflag][arflag];

// 条件達成フラグ
bool archieve(int x,int k) {
    // your code
    return true;
}

void dpInit() {
    rep(i,keta) rep(j,miflag) rep(k,arflag) dp[i][j][k] = 0;
}

// v:上限 n:桁数 self:自分自身を含むか
ll ketaDP(vi &v,int n,bool self = true) {
  dpInit();
  dp[0][0][0] = 1;

  rep(i,n) rep(j,2) rep(k,2) rep(x,j ? 10 : v.at(i) + 1) {
    dp[i+1][j or x < v.at(i)][k or archieve(x,k)] += dp[i][j][k];
  }
  if(self) return dp[n][1][1] + dp[n][0][1];
  else return dp[n][1][1];
}
