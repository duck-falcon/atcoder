/*
d[x] = a : x の親が a
d[y] = -10: y が根でありそのサイズ(木の全ノードの数)が10
*/
struct UnionFind {
  vi d;
  UnionFind(int n = 0) : d(n, -1) {}
  // x の根を求める
  int find(int x) {
    if(d[x] < 0) return x;
    return d[x] = find(d[x]); // d[1] = 2, d[2] = 4 の時 d[1] = 4　に付け替えて短縮する
  }
  // x の属する木と y の属する木を合体する
  // 小さい方の木を大きい方の木にくっつける
  bool unite(int x, int y) {
    int rx = find(x); int ry = find(y);
    if(rx == ry) return false; // 同じ木に属する場合
    if(-d[rx] < -d[ry]) swap(rx, ry); // xのサイズ > y のサイズにする
    d[rx] += d[ry]; // size 反映
    d[ry] = rx; // rx を親に付け替える
    return true;
  }
  // x と y　が同じ木に属するかを判定する
  bool same(int x, int y) {
    return find(x) == find(y);
  }
  int size(int x) {
    return -d[x];
  }
  void print() {
    cout << d << endl;
  }
};