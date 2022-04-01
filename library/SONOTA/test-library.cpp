#include <bits/stdc++.h>
using namespace std;
// rep
#define rep(i,n)    for(decltype(n) i = 0; i < (n) ; ++i)
#define orep(i,n)   for(decltype(n) i = 1; i <= (n); ++i)   // one rep
#define drep(i,n)   for(auto  i = (n)-1; i >= static_cast<decltype(i)>(0); --i) // down rep
#define srep(i,s,t) for(auto  i = (s); i < (t); ++i)  // set rep

// func
#define rng(x)  (x).begin(),(x).end() // range
#define rrng(a) (a).rbegin(),(a).rend() // reverse range
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define ru(x,y) (((x)+(y)-1)/(y)) // round up

// replace
#define fi first
#define se second
#define eb emplace_back
#define fcout cout << fixed << setprecision(15)
#define LL_MIN std::numeric_limits<long long>::min()
#define LL_MAX std::numeric_limits<long long>::max()

// type
using ll  = long long;
using P   = pair<int,int>;
using vi  = vector<int>;
using vvi = vector<vi>;
using vp  = vector<P>;
using vvp = vector<vp>;
using vl  = vector<ll>;
using rpq = priority_queue<int,vi,less<int>>;   // 大きい順
using pq  = priority_queue<int,vi,greater<int>>;// 小さい順

const int INF = 1001001001;
const ll LINF = 10010010011001001001;

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

  return 0;
}
