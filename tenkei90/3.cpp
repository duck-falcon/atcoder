#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)    for(long long i = 0; i < (n) ; ++i)

#define eb emplace_back

using vi  = vector<int>;
using vvi = vector<vi>;

// dfs-tree

// 頂点数、辺数
int vertices,sides;
// グラフ
vvi maze;
// 既に到達した点
vi seen;
// ある地点からの最短距離,閉路を含まない場合のみ短時間で計算可能（木など）
vi d;

int max_d;
int max_idx;

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

int main() {

  cin >> vertices;
  sides = vertices - 1;
  // ある点からの距離は最初無限大で初期化
  d = vi(vertices,INF);

  maze = vvi(vertices,vi());
  seen = vi(vertices,0);
  rep(i,sides) {
    int a,b;cin >> a >> b;
    a--;b--;
    maze.at(a).eb(b);
    maze.at(b).eb(a);
  }

  max_d = 0;
  max_idx = 0;
  dfsLength(0, 0);

  rep(i,d.size()) {
    if(max_d < d.at(i)) {
      max_d = d.at(i);
      max_idx = i;
    }
  }

  // 再度初期化
  d = vi(vertices,INF);
  seen = vi(vertices,0);

  dfsLength(max_idx, 0);
  max_d = 0;

  rep(i,d.size()) {
    max_d = max(max_d,d.at(i));
  }
  cout << max_d + 1<< endl;

  return 0;
}
