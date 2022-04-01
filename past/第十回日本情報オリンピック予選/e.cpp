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

const int INF = 100100101;
int main() {
  int h,w,n;
  cin >> h >> w >> n;
  vvi maze(h,vi(w,0));
  P start;
  rep(i,h) rep(j,w) {
    char c;
    cin >> c;
    int t;
    if(c=='S') {
      t = 0;
      start=P(i,j);
    }
    else if(c=='.') t = 10;
    else if(c=='X') t = -1;
    else t=c-'0';
    maze.at(i).at(j) = t;
  }

  int ans = 0;
  int dx[4] = {1,0,-1,0};
  int dy[4] = {0,1,0,-1};
  orep(i,n) {
    int score[h][w];
    rep(k,h) rep(j,w) score[k][j] = INF;
    queue<P> que;
    que.push(start);
    score[start.fi][start.se] = 0;
    while(que.size()) {
      P now = que.front();que.pop();
      rep(k,4) {
        int nx = now.fi + dx[k];int ny = now.se + dy[k];
        if(isin(nx,0,h) and isin(ny,0,w) and maze[nx][ny] != -1 and score[nx][ny] == INF) {
          que.push(P(nx,ny));
          score[nx][ny] = score[now.fi][now.se] + 1;
          if(maze[nx][ny]==i) {
            ans+=score[nx][ny];
            start = P(nx,ny);
            break;
          }
        }
      }
    }
  }

  cout << ans << endl;


  return 0;
}
