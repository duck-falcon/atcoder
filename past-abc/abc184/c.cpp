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

int main() {
  ll rs,cs,rg,cg;cin >> rs >> cs >> rg >> cg;

  if(rs==cs and rg == cg) {
    cout << 0 << endl;
    return 0;
  }

  // 正方形部分
  if(isin(rg,rs-2,rs+3) and isin(cg,cs-2,cs+3)) {
    cout << 1 << endl;
    return 0;
  }

  // 突起部分
  if((rg==rs+3 and cg==cs) or (rg==rs and cg==cs+3) or (rg==rs-3 and cg==cs) or (rg==rs and cg==cs-3)) {
    cout << 1 << endl;
    return 0;
  }

  // naname
  if(rg == cg + rs - cs or rg == -cg + cs + rs) {
    cout << 1 << endl;
    return 0;
  }

  if((rs-cs+rg+cg)%2==0) {
    cout << 2 << endl;
    return 0;
  }

  ll a,b;
  a = cs+2;b=rs-1;
  rep(i,4) {
    if(rg == cg - b + a) {
      cout << 2 << endl;
      return 0;
    }
    a--;b++;
  }

  a = cs-1;b=rs-2;
  rep(i,4) {
    if(rg == -cg + b + a) {
      cout << 2 << endl;
      return 0;
    }
    a++;b++;
  }

  if(abs((cs+rs)-(cg+rg))<=6) {
    cout << 2 << endl;
    return 0;
  }

  cout << 3 << endl;

  return 0;
}
