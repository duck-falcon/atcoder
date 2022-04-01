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
  const int INF = 1001001001;
int main() {
  int n;cin >> n;
  vl a(n,0);
  rep(i,n) cin >> a.at(i);

  ll ans = 0;
  vl s(n+1,0ll);
  vl mx(n+1,0ll);
  rep(i,n) {
    s.at(i+1) = s.at(i) + a.at(i);
    mx.at(i+1) = max(mx.at(i),s.at(i+1));
  }
  vl v(n+1,0ll);
  rep(i,n) {
    v.at(i+1) = s.at(i+1) + v.at(i);
  }

  orep(i,n-1) {
    ans = max(ans,v.at(i)+mx.at(i+1));
  }
  if(n==1 and a.at(0) > 0) {
    cout << a.at(0) << endl;
    return 0;
  }

  cout << ans << endl;

  return 0;
}
