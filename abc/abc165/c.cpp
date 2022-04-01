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
vi a(10);
int n,m,q;
vvi p (50,vi(4,0));

void g() {
  ll point=0;
  rep(i,q) {
    vi t = p.at(i);
    if(a.at(t.at(1)-1)-a.at(t.at(0)-1)==t.at(2)) point+=t.at(3);
  }
  ans = max(ans,point);
 }

void f(int x,int si) {
  a.at(si) = x;
  si++;
  if(si == n) {
    g();
    return;
  }
  srep(i,x,m+1) f(i,si);
}

int main() {
  cin >> n >> m >> q;
  rep(i,q) rep(j,4) cin >> p.at(i).at(j);

  orep(i,m) f(i,0);
  cout << ans << endl;

  return 0;
}
