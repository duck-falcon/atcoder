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

int main() {
  int n,m;
  cin >> n >> m;
  vvi a(n,vi(1,0));
  rep(i,n) a.at(i).at(0) = i;

  rep(i,m) {
    int x,y;
    cin >> x >> y;
    a[x-1].eb(y-1);
    a[y-1].eb(x-1);
  }

  int ans = 0;
  rep(i,1 << n) {
    vi t;
    rep(j,n) if(i >> j & 1) t.eb(j);
    int si = t.size();
    bool flag = false;
    rep(j,si) {
      rep(k,t.size()) {
        flag = false;
        for(auto v : a.at(t.at(j))) if(t.at(k) == v) flag = true;
        if (flag == false) break;
      }
      if (flag == false) break;
    }
    if(flag) ans = max(ans,si);
  }
  cout << ans << endl;
  return 0;
}
