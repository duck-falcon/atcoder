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

const int INF = 100100101;
int main() {
  int n,k; cin >> n >> k;
  vi v(n,0);
  rep(i,n) cin >> v.at(i);

  ll sum = 0;
  // 左右合計でx個とる
  orep(x,min(n,k)) {
    rep(hidari,x+1) {
      ll tmpsum = 0;
      // sort用
      vi t(n,INF);
      // 左からとる
      rep(i,hidari) {
        tmpsum += v.at(i);
        t.at(i) = v.at(i);
      }
      // 右からとる
      orep(i,x-hidari) {
        tmpsum+=v.at(n-i);
        t.at(n-i) = v.at(n-i);
      }
      sort(rng(t));

     // -が大きい順に捨てられるだけ捨てる
      rep(i,k-x) {
        if(t.at(i)<0) tmpsum -= t.at(i);
        else break;
      }
      sum = max(sum,tmpsum);
    }
  }
  cout << sum << endl;

  return 0;
}
