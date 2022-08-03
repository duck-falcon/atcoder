#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)    for(long long i = 0; i < (n) ; ++i)
#define orep(i,n)   for(long long i = 1; i <= (n); ++i)   // one rep
#define drep(i,n)   for(long long i = (n)-1; i >= 0; --i) // down rep
#define srep(i,s,t) for(long long i = (s); i < (t); ++i)  // set rep
#define rng(x)  (x).begin(),(x).end() // range
#define rrng(a) (a).rbegin(),(a).rend() // reverse range
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define ru(x,y) (((x)+(y)-1)/(y)) // round up
#define fi first
#define se second
#define eb emplace_back
#define fcout cout << fixed << setprecision(15)

using ll  = long long;
using P   = pair<int,int>;
using vi  = vector<int>;
using vvi = vector<vi>;
using vp  = vector<P>;
using vvp = vector<vp>;
using vl  = vector<ll>;
using rpq = priority_queue<int,vi,less<int>>;   // 大きい順
using pq  = priority_queue<int,vi,greater<int>>;// 小さい順

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

struct V{
  ll x,y;
  V(ll x = 0, ll y = 0) : x(x),y(y) {}
  void print() {
    cout << x << " " << y << endl;
  }
};

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

int main() {
  int n;cin >> n;

  V s,t;
  cin >> s.x >> s.y >> t.x >> t.y;

  vector<V> p(n+2);
  vl r(n+2,0);

  auto pow2 = [] (ll x){
    return x*x;
  };
  auto dist2 = [&] (V a, V b) {
    return pow2(a.x - b.x) + pow2(a.y - b.y);
  };

  int sp,tp;
  // どの円に乗っているか
  rep(i, n) {
    cin >> p[i].x >> p[i].y >> r[i];
    if( dist2(p[i], s) == pow2(r[i]) ) sp = i;
    if( dist2(p[i], t) == pow2(r[i]) ) tp = i;
  }

  UnionFind uf = UnionFind(n+1);
  auto overlap = [&] (int i, int j) {
    return dist2(p[i], p[j]) <= pow2(r[i] + r[j]) and dist2(p[i], p[j]) >= pow2(r[i] - r[j]);
  };
  rep(i, n) {
    srep(j, i+1, n) {
      if(overlap(i, j)) uf.unite(i,j);
    }
  }
  Yes(uf.find(sp) == uf.find(tp));


  return 0;
}
