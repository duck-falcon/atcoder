// dfs-tree

// 頂点数、辺数
int vertices,sides;
// グラフ
vvi maze;
// 既に到達した点
vi seen;
// ある地点からの最短距離,閉路を含まない場合のみ短時間で計算可能（木など）
vi d;

const int INF = 100100101;

void dfsLength(int x, int length) {
  int sz = maze.at(x).size();
  seen.at(x) = 1;
  d.at(x) = min(d.at(x),length);
  rep(i,sz) {
    int nx = maze.at(x).at(i);
    if(!seen.at(nx)) dfsLength(nx,length+1);
  }
}

void dfs(int x) {
  int sz = maze.at(x).size();
  seen.at(x) = 1;
  rep(i,sz) {
    int nx = maze.at(x).at(i);
    if(!seen.at(nx)) dfs(nx);
  }
}

int main() {

  cin >> vertices;
  cin >> sides;

  maze = vvi(vertices,vi());
  seen = vi(vertices,0);
  rep(i,sides) {
    int a,b;cin >> a >> b;
    a--;b--;
    maze.at(a).eb(b);
    maze.at(b).eb(a);
  }

  // つながっている頂点グループの数
  /*int ans = 0;
  rep(i,vertices) {
    if(!seen.at(i)) {
      dfs(i);
      ans++;
    }
  }

  cout << ans << endl;*/

  // start からの最短距離を全部求める
  /*int start = 3;
  d = vi(vertices,INF);
  dfsLength(start,0);*/

  return 0;
}
