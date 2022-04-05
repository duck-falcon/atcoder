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

bool issquare(ll x){
  ll k = 0;
  cout << x << endl;
  bool ans = false;
  while(k * k < x) {
    if(k*k == x) ans = true;
    k+=1;
  }
  return ans;
}

int main() {
  ll n;cin >> n;

  ll max = 1000001;
  vl triple(max,0);
  rep(i,max) triple.at(i) = i*i*i;

  rep(i,max) {
    cout << triple.at(i) << endl;
    if(triple.at(i) < n) continue;
    if(triple.at(i) % 2 != n) continue;
    ll A = i;
    ll B = (triple.at(i) - n) / 2*A;
    ll D = A * A - 4 * B;
    if(!issquare(D)) continue;
    ll d = sqrt(D);
    if(A - d < 0 ) continue;
    if(A % 2 != d % 2) continue;
    cout << triple.at(i) - 2*A*B << endl;
    break;
  }

  return 0;
}
