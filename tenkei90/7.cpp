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

const int INF = 2111010000;
vi a(400000,INF);
bool okcheck(int mid, int b)  {
    if(a.at(mid) >= b) return true;
    return false;
};

int binary_search (int n, int b) {
  int ok_idx = n;int ng_idx = -1;
  // int ok_idx = -1;int ng_idx = n;
  
  while(abs(ok_idx - ng_idx) > 1) {
    int mid = (ok_idx + ng_idx) / 2;
    if(okcheck(mid, b)) ok_idx = mid;
    else ng_idx = mid;
  }
  
  if(ng_idx == -1) ng_idx = 0;
  return min(abs(a.at(ok_idx) - b) , abs(a.at(ng_idx)-b));
  // return ng_idx;
}


int main() {
    int n;cin >> n;

    rep(i,n) cin >> a.at(i);
    sort(rng(a));

    int q;cin >> q;
    rep(i,q) {
        int b;cin >> b;
        cout << binary_search(n+1, b) << endl;
    }

  return 0;
}
