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
  int n;cin >> n;
  rpq mae;
  pq ushiro;
  ll sum;
  int minx;

  // 一回目
  int t;cin >> t;
  cin >> minx >> sum;
  mae.push(minx);ushiro.push(minx);

  rep(i,n-1) {
    int q;cin >> q;
    if(q==1) {
      int a,b;cin >> a >> b;
      sum+=b;

      // 最小値更新
      int l = mae.top();int r = ushiro.top();
      if(!isin(a,l,r+1)) {
        sum += min(abs(l-a),abs(r-a));
      }

      // 中央値更新
      mae.push(a);ushiro.push(a);
      if(mae.top() > ushiro.top()) {
        int x = mae.top();
        int y = ushiro.top();
        mae.pop();ushiro.pop();
        mae.push(y);ushiro.push(x);
      }
      minx = mae.top();
    } else {
      cout << minx << " " << sum << endl;
    }
  }
}
