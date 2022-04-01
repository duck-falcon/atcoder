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

ll ans = 0;
int n,m,q;
vi a,b,c,d;

void dfs(vi A) {
  if(A.size() == n+1) {
    ll point = 0;
    rep(i,q) if(A.at(b.at(i))-A.at(a.at(i))==c.at(i)) point+=d.at(i);
    ans = max(ans,point);
    return;
  }
  int t = A.back();
  srep(i,t,m+1) {
    A.eb(i);
    dfs(A);
    A.pop_back();
  }

}

int main() {
  cin >> n >> m >> q;
  a=b=c=d=vi(q,0);
  rep(i,q) cin >> a.at(i) >> b.at(i) >> c.at(i) >> d.at(i);

  dfs(vi(1,1));
  cout << ans << endl;

  return 0;
}
