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
bool checked[50][50];

int main() {
  int h,w;
  cin >> h >> w;
  h--;w--;
  checked[0][0] = true;

  int white=0;
  char meiro[h+1][w+1];
  rep(i,h+1) rep(j,w+1) {
    cin >> meiro[i][j];
    if(meiro[i][j] == '.') white++;
  }
  queue<P> que;
  que.push(P(0,0));
  int dx[] = {1,-1,0,0},dy[] = {0,0,-1,1};
  vector<vector<vector<P>>> route(h+1,vector<vector<P>>(w+1));
  route[0][0].emb(P(0,0));

  while(que.size()) {
    P tmp = que.front();que.pop();
    rep(i,4) {
      int nx = tmp.fi + dx[i],ny = tmp.se + dy[i];
      if(0 <= nx and nx <= h and 0 <= ny and ny <= w and meiro[nx][ny] == '.' and !checked[nx][ny]) {
        checked[nx][ny] = true;
        route[nx][ny] = route[tmp.fi][tmp.se];
        route[nx][ny].emb(P(tmp.fi,tmp.se));
        que.push(P(nx,ny));
        if(nx==h and ny == w) {
          cout << white - route[nx][ny].size() << endl;
          return 0;
        }
      }
    }
  }
  cout << "-1" << endl;
  return 0;
}
