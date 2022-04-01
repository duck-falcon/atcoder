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
int ww ,hh;

vvi tate(vvi v,int h) {
  rep(k,hh) {
    if(h>>k&1) rep(i,ww) v.at(k).at(i) = 0;
  }
  return v;
}

vvi yoko(vvi v,int w) {
  rep(k,ww) {
    if(w>>k&1) rep(i,hh) v.at(i).at(k) = 0;
  }
  return v;
}

int cnt(vvi v) {
  int ans=0;
  rep(i,hh) rep(j,ww) if(v.at(i).at(j)) ans++;
  return ans;
}


int main() {
  int k;
  cin >> hh >> ww >> k;
  vvi maze(hh,vi(ww,0));

  rep(i,hh) {
    string s;cin >> s;
    rep(j,ww) {
      char c;
      c=s.at(j);
      if(c=='.') maze.at(i).at(j) = 0;
      else maze.at(i).at(j) = 1;
    }
  }

  int ans = 0;

  rep(i,1<<hh) {
    vvi copy = maze;
    copy=tate(copy,i);
    rep(j,1<<ww) {
      vvi copy2 = copy;
      copy2=yoko(copy2,j);
      if(cnt(copy2)==k) ans++;
    }
  }
  cout << ans << endl;

  return 0;
}
