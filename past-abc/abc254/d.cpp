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
const int INF = 1001001011;

int main() {

  ll n; cin >> n;
  vi sq = vi(n+5, INF);
  orep(i, n) {
    if(i * i > n) break;
    sq.at(i) = i * i;
  }
  sq.at(0) = 0;

  ll ans = 0;
  vl koku = vl(n+5, 1);
  orep(i,n) koku.at(i) = i;

  drep(i, n) {
    orep(j, n) {
      if(sq.at(i)*j > n) break;
      koku.at(sq.at(i)*j) = min(koku.at(sq.at(i)*j), j);
    }
  }

  orep(i, n) {
    /*ll t = i;
    drep(i, n) {
      if(sq.at(i) == 0) break;
      if(t % sq.at(i) == 0) {
        t /= sq.at(i);
        break;
      }
    }
    ans += upper_bound(rng(sq), n / t) - sq.begin() -1;*/
    ans += upper_bound(rng(sq), n / koku.at(i)) - sq.begin() -1;
  }
  cout << ans << endl;

  return 0;
}
