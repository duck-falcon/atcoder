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

// switch を on にする,つまり対応するpcopyの値を増やす
void on(vi &sw,vi &tmpp) {
  rep(i,sw.size()) {
    tmpp.at(sw.at(i))++;
  }
}

int main() {
  int n,m;cin >> n >> m;
  // sw[スイッチ][スイッチにつながっている電球]
  vvi sw(n,vi());

  rep(i,m) {
    int k;cin >> k;
    rep(j,k) {
      int s;cin >> s;
      s--;
      sw.at(s).eb(i);
    }
  }

  vi p(m,0);
  rep(i,m) cin >> p.at(i);

  int ans = 0;
  rep(i,1<<n) {
    // loop ごとに電球につながっている switch のうち on になっているものを数える
    vi tmpp(m,0);
    bool flag = true;
    rep(j,n) if(i>>j&1) {
      on(sw.at(j),tmpp);
    }
    // p と tmpp が一つでも一致しないと false
    rep(j,m) if(tmpp.at(j)%2!=p.at(j)) flag = false;
    if(flag) ans++;
  }

  cout << ans << endl;

  return 0;
}
