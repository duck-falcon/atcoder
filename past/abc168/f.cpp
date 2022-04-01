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

struct L {
  int a,b,c;
  L(int a,int b,int c) : a(a),b(b),c(c) {}
};


int main() {
  int n,m;
  cin >> n >> m;
  // convert x,y -> X,Y
  map<int,int> X;
  map<int,int> Y;
  X[0]=0;
  Y[0]=0;


  // length 用
  vector<L> lx;
  vector<L> ly;
  rep(i,n) {
    int a,b,c;
    cin >> a >> b >> c;
    X[a]=0;
    X[b]=0;
    Y[c]=0;
    lx.eb(L(a,b,c));
  }

  rep(i,m) {
    int d,e,f;
    cin >> d >> e >> f;
    X[d]=0;
    Y[e]=0;
    Y[f]=0;
    ly.eb(L(e,f,d));
  }
  // sort x,y
  vi xs;
  vi ys;
  for(auto &v : X) {
    v.se=xs.size();
    xs.eb(v.fi);
  }
  for(auto &v : Y) {
    v.se=ys.size();
    ys.eb(v.fi);
  }
  int h=xs.size()*2;int w=ys.size()*2;
  vvi d(h,vi(w,0));


  // wall
  for(auto l : lx) {
    srep(i,X[l.a]*2,X[l.b]*2) {
      d[i][Y[l.c]*2]=-1;
    }
  }
  for(auto l : ly) {
    srep(i,Y[l.a]*2,Y[l.b]*2) {
      d[X[l.c]*2][i]=-1;
    }
  }

  vi dx = {-1,0,1,0};vi dy={0,1,0,-1};
  // bfs
  queue<P> que;
  que.push(P(X[0]*2,Y[0]*2));
  d[X[0]*2][Y[0]*2]=1;
  while(que.size()) {
    P now=que.front();que.pop();
    rep(i,4) {
      int nx=now.fi+dx[i];int ny=now.se+dy[i];
      if(isin(nx,0,h) and isin(ny,0,w) and d[nx][ny]==0){
        d[nx][ny]=1;
        que.push(P(nx,ny));
      }
    }
  }

  ll ans=0;
  // S calc
  rep(i,h) rep(j,w) {
    if(d[i][j]!=1) continue;
    if(i==h-1 or i == 0 or j == 0 or j == w-1) {
      cout << "INF" << endl;
      return 0;
    }
    if(i % 2 == 0 or j % 2 == 0) continue;
    ll ex=xs[i/2+1]-xs[i/2];
    ll ey=ys[j/2+1]-ys[j/2];
    ans+=ex*ey;
  }

  cout << ans << endl;

  return 0;
}
