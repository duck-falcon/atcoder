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
using vvp = vector<vp>;
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

// bfs-tree

// 頂点数、辺数
int vertices,sides;
// グラフ
vvp maze;
// ある地点からの偶奇
vi d;


const int INF = 100100101;

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
        d.at(np.fi) = (d.at(p.fi) + np.se) % 2;
      }
    }
  }
}

int main() {

  cin >> vertices;
  sides = vertices - 1;

  // fi 辺の隣接関係 ,se 距離
  maze = vvp(vertices,vp());
  // -1 は来たことない, 偶奇判定用
  d = vi(vertices,-1);
  rep(i,sides) {
    int a,b,c;cin >> a >> b >> c;
    a--;b--;
    maze.at(a).eb(P(b,c%2));
    maze.at(b).eb(P(a,c%2));
  }

  bfs(0);
  rep(i,d.size()) cout << d.at(i) << endl;

  return 0;
}
