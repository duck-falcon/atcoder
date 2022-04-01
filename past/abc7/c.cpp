#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n) ; ++i)
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define emb emplace_back
#define fcout cout << fixed << setprecision(15)


using namespace std;
using ll = long long;
using P = pair<int,int>;

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

int INF = 100100100;
int main() {
  int r,c;
  cin >> r >> c;
  int sy,sx,gy,gx;
  cin >> sy >> sx >> gy >> gx;
  sy--;sx--;gy--;gx--;
  int d[r][c];
  rep(i,r) rep(j,c) d[i][j] = INF;
  char meiro[r][c];

  rep(i,r) rep(j,c) cin >> meiro[i][j];

  queue<P> bfs;
  bfs.push(P(sy,sx));
  d[sy][sx] = 0;
  vector<int> dx = {0,1,0,-1};
  vector<int> dy = {1,0,-1,0};
  while(bfs.size()) {
    P now = bfs.front();bfs.pop();
    rep(i,4) {
      int x = now.se + dx[i];
      int y = now.fi + dy[i];
      if( (meiro[y][x] != '#') and (d[y][x] == INF)) {
        bfs.push(P(y,x));
        d[y][x] = d[now.fi][now.se] + 1;
      }
    }
  }
  cout << d[gy][gx] << endl;

  return 0;
}
