// bfs-tree

// 頂点数、辺数
int vertices,sides;
// グラフ
vvi maze;
// ある地点からの最短距離

vi d;

const int INF = 100100101;

void bfs(int x) {
  queue<int> que;
  que.push(x);
  d.at(x) = 0;

  while(que.size()) {
    x = que.front();que.pop();
    rep(i,maze.at(x).size()) {
      int nx = maze.at(x).at(i);
      if(d.at(nx) == -1) {
        que.push(nx);
        d.at(nx) = d.at(x) + 1;
      }
    }
  }
}

/* 複数値を持っているとき pair版
void bfs(int x) {
  queue<P> que;
  que.push(P(x,0));
  d.at(x) = 0;

  while(que.size()) {
    P p = que.front();que.pop();
    rep(i,maze.at(p.fi).size()) {
      P np = maze.at(p.fi).at(i);
      if(d.at(np.fi) == -1) {
        que.push(np);
        d.at(np.fi) = d.at(p.fi) + np.se;
      }
    }
  }
}*/

int main() {

  cin >> vertices;
  cin >> sides;

  maze = vvi(vertices,vi());
  // -1 は来たことない
  d = vi(vertices,-1);
  rep(i,sides) {
    int a,b;cin >> a >> b;
    a--;b--;
    maze.at(a).eb(b);
    maze.at(b).eb(a);
  }

  // つながっている頂点グループの数
  int ans = 0;
  rep(i,vertices) {
    if(d.at(i)==-1) {
      bfs(i);
      ans++;
    }
  }

  cout << ans << endl;

  // start からの最短距離を全部求める
  /*int start = 3;
  d = vi(vertices,INF);
  dfsLength(start,0);*/

  return 0;
}
