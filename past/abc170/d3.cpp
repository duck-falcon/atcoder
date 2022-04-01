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
  int n;
  cin >> n;
  const int mx = 1000005;
  vi a;
  vi na;
  vi hurui(mx,0);
  vi tyouhuku(mx,0);
  rep(i,n) {
    int t;
    cin >> t;
    tyouhuku.at(t)++;
  }
  rep(i,mx) {
    if(tyouhuku.at(i)) a.eb(i);
    if(tyouhuku.at(i)==1) na.eb(i);
  }


  rep(i,a.size()) {
    int ai = a.at(i);
    int tmp  = ai;
    while(ai<mx) {
      hurui[ai]++;
      ai+=tmp;
    }
  }
  int ans = 0;
  rep(i,na.size()) {
    if(hurui.at(na.at(i)) == 1) ans++;
  }
  cout << ans << endl;


  return 0;
}
