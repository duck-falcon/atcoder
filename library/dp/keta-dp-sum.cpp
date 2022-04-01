// 条件をみたす数が何個あるか知りたいときの桁dp

const int keta = 100;
const int miflag = 2;
const int arsum = keta;
//桁 未満フラグ 条件達成数
ll dp[keta][miflag][arsum];

// 条件達成フラグ
bool archieve(int x,int k) {
    // your code
    return true;
}

int archieveNum(int x,int k) {
  if(archieve(x,k)) return k+1;
  else return k;
}

void dpInit() {
    rep(i,keta) rep(j,miflag) rep(k,arsum) dp[i][j][k] = 0;
}

// v:上限 n:桁数 self:自分自身を含むか
ll ketaDP(vi &v,int n,int anum,bool self = true) {
  dpInit();
  dp[0][0][0] = 1;

  rep(i,n) rep(j,2) rep(k,n) rep(x,j ? 10 : v.at(i) + 1) {
    dp[i+1][j or x < v.at(i)][archieveNum(x,k)] += dp[i][j][k];
  }
  // anum = 条件達成数
  if(self) return dp[n][1][anum] + dp[n][0][anum];
  else return dp[n][1][anum];
}
