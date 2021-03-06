#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)    for(long long i = 0; i < (n) ; ++i)
#define orep(i,n)   for(long long i = 1; i <= (n); ++i)   // one rep
#define drep(i,n)   for(long long i = (n)-1; i >= 0; --i) // down rep
#define srep(i,s,t) for(long long i = (s); i < (t); ++i)  // set rep
#define rng(x)  (x).begin(),(x).end() // range
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

ostream& operator<<(ostream& os, const P& p) { return os << "<" << p.fi << ","<< p.se << ">";}

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
  os << "[";
  for (int i = 0; i < (int)vec.size(); ++i)
  {
    cout << (i > 0 ? ", " : "") << vec.at(i);
  }
  os << "]";
  return os;
}

template<typename T>
ostream& operator<<(ostream& os, const vector<vector<T>>& vec) {
  os << "[";
  for(auto& v : vec) {
    os << v << (vec.back() != v ? "," : "");
  }
  os << "]";
  return os;
}

int main() {

  return 0;
}
