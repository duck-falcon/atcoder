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

int main() {
  int n; cin >> n;
  vi a(3*n,0);
  rep(i,3*n) cin >> a.at(i);

  priority_queue<int,vi,greater<int>> mae;
  ll maesum = 0;
  rep(i,n) {
    mae.push(a.at(i));
    maesum+=a.at(i);
  }

  vl maesums(n+1,0);
  maesums.at(0) = maesum;
  srep(i,n,2*n) {
    if(mae.top() < a.at(i)) {
      maesum-=mae.top();
      mae.pop();
      maesum+=a.at(i);
      mae.push(a.at(i));
    }
    maesums.at(i+1-n) = maesum;
  }

  reverse(rng(a));
  priority_queue<int> ushiro;
  ll ushirosum = 0;
  rep(i,n) {
    ushiro.push(a.at(i));
    ushirosum+=a.at(i);
  }
  vl ushirosums(n+1,0);
  ushirosums.at(0) = ushirosum;
  srep(i,n,2*n) {
    if(ushiro.top() > a.at(i)) {
      ushirosum-=ushiro.top();
      ushiro.pop();
      ushirosum+=a.at(i);
      ushiro.push(a.at(i));
    }
    ushirosums.at(i+1-n) = ushirosum;
  }
  reverse(rng(ushirosums));

  ll ans = -100000000000000000101010;
  rep(i,n+1) ans = max(ans,maesums.at(i)-ushirosums.at(i));

  cout << ans << endl;

  return 0;
}
