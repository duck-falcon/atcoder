#include <bits/stdc++.h>
using namespace std;
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

// bfs-tree

// 頂点数、辺数
int vertices,sides;
// グラフ
vvi maze;
// ある地点からの最短距離

vvi dd;
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
  int k;cin >> k;
  vi c(k,0);
  rep(i,k) {
    cin >> c.at(i);
    c.at(i)--;
  }

  dd = vvi(k,vi(vertices,-1));

  rep(i,c.size()) {
      bfs(c.at(i));
      dd.at(i) = d;
      d = vi(vertices,-1);
  }

  vvi di = vvi(k,vi(k,-1));
  rep(i,k) {
    rep(j,k) di.at(c.at(i)).at(j) = dd.at(c.at(i)).at(c.at(j));
  }

  

  cout << ans << endl;

  // start からの最短距離を全部求める
  /*int start = 3;
  d = vi(vertices,INF);
  dfsLength(start,0);*/

  return 0;
}
