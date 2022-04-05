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

int main() {
  // h w のこと
  int h,w;
  cin >> h >> w;
  vvi maze = vvi(h+1,vi(w+1,0));
  vvi horizontal = vvi(h+1,vi(w+1,0));
  rep(i,h+1) maze.at(i).at(w) = 0;
  vvi vertical   = vvi(h+1,vi(w+1,0));
  rep(i, h) {
    string s; cin >> s;
    rep(j, w) {
      if(s.at(j)=='.') maze.at(i).at(j) = 1;
      else if (s.at(j)=='#') maze.at(i).at(j) = 0;
    }
  }

  rep(i,h) {
    ll now = -1;
    rep(j,w+1) {
      if(maze.at(i).at(j)==0) {
        srep(k,now+1,j) horizontal.at(i).at(k) = max(j - now - 1ll,0ll);
        now = j;
      }
    }
  }

  rep(i,w) {
    ll now = -1;
    rep(j,h+1) {
      if(maze.at(j).at(i)==0) {
        srep(k,now+1,j) vertical.at(k).at(i) = max(j - now - 1ll,0ll);
        now = j;
      }
    }
  }

  int ans = 0;
  rep(i,h) rep(j,w) ans = max(ans,horizontal.at(i).at(j) + vertical.at(i).at(j));
  cout << ans -1 << endl;


  return 0;
}
