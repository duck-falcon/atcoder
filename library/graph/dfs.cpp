// dfs
/*
ある地点からの距離を測る問題は bfs のがよい
dfs だと 500*500 で TLEする
*/

// 行、列
int rows,columns;
// 長方形グリッド
vvi maze;
// 既に到達した点
vvi seen;
// ある地点からの最短距離
vvi d;
// start goal
int sx,sy,gx,gy;

const int INF = 100100101;

// 4方向
vi dx = {1,0,-1,0}, dy = {0,1,0,-1};
// 8方向
// vi dx = {1,1,0,-1,-1,-1,0,1}, dy = {0,1,1,1,0,-1,-1,-1};


void dfs(int x, int y) {
  int n = dx.size();
  seen.at(x).at(y) = 0;
  rep(i,n) {
    int nx = x + dx.at(i), ny = y + dy.at(i);
    if(isin(nx,0,columns) and isin(ny,0,rows) and maze.at(nx).at(ny) and !seen.at(nx).at(ny)) dfs(nx,ny);
  }
}

void dfsLength(int x, int y, int length) {
  int n = dx.size();
  // 今の最短距離よりも長い場合は skip
  if(d.at(x).at(y) <= length) return;
  d.at(x).at(y) = length;
  rep(i,n) {
    int nx = x + dx.at(i), ny = y + dy.at(i);
    if(isin(nx,0,columns) and isin(ny,0,rows) and maze.at(nx).at(ny)) dfsLength(nx,ny,length+1);
  }
}

// 入力整形例
int main() {
  // h w のこと
  cin >> columns >> rows;
  maze = vvi(columns,vi(rows,0));
  seen = vvi(columns,vi(rows,0));
  rep(i, columns) {
    string s; cin >> s;
    rep(j, rows) {
      if(s.at(j)=='.') maze.at(i).at(j) = 1;
      else if (s.at(j)=='#') maze.at(i).at(j) = 0;
//      else if (s.at(j) == 's') {sx = i; sy = j;maze.at(i).at(j)=1;}
//      else if (s.at(j) == 'g') {gx = i, gy = j;maze.at(i).at(j)=1;}
    }
  }

  // start からの最短距離を全部求める -> bfs のほうが良い
  /*d = vvi(columns,vi(rows,INF));
  dfsLength(sx,sy,0);*/

  return 0;
}
