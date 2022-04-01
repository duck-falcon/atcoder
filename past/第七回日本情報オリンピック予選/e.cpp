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


int main() {
  int r,c;
  cin >> r >> c;
  vvi moti(r,vi(c,0));

  rep(i,r) rep(j,c) cin >> moti.at(i).at(j);

  auto revv = [&](int rr) {
    rep(j,c) {
      if(moti.at(rr).at(j)) moti.at(rr).at(j) = 0;
      else moti.at(rr).at(j) = 1;
  }
};
  int ans = 0;
  rep(i,1<<r) {
    rep(j,r) if(i>>j&1) revv(j);
    int tans=0;
    rep(j,c) {
      int tate = 0;
      rep(k,r) {
        if(moti.at(k).at(j)) tate++;
      }
    tans+=max(tate,r-tate);

    }
  ans=max(ans,tans);
  rep(j,r) if(i>>j&1) revv(j);
}
  cout << ans << endl;

  return 0;
}
