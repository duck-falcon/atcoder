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

vi dx={1,0,-1,0},dy={0,1,0,-1};
const int INF = 100100101;
int main() {
  int h,w;
  cin >> h >> w;

  vvi maze(h,vi(w,0));
  rep(i,h) rep(j,w) {
    char a;
    cin >> a;
    if(a=='.') maze.at(i).at(j)=1;
    else maze.at(i).at(j)=0;
  }

  vvi defa(h,vi(w,INF));

  int ans=0;
  rep(i,h) rep(j,w) {
    if(!maze.at(i).at(j)) continue;
    queue<P>  que;
    que.push(P(i,j));
    int tmp=0;
    vvi d=defa;
    d.at(i).at(j)=0;
    while(que.size()) {
      P q=que.front();que.pop();
      int x=q.fi,y=q.se;
      rep(k,4) {
        int nx=x+dx[k];int ny = y+dy[k];
        if(isin(nx,0,h) and isin(ny,0,w) and maze.at(nx).at(ny)==1 and d.at(nx).at(ny)==INF) {
          que.push(P(nx,ny));
          d[nx][ny]=d[x][y]+1;
          tmp=max(tmp,d[x][y]+1);
        }
      }
    }
    ans=max(ans,tmp);
  }

  cout << ans << endl;

  return 0;
}
