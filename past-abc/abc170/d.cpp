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

const int mx=1000006;
int hurui[mx];
const int INF = 100100101;
int main() {
  int n;
  cin >> n;
  vi a(n,0);
  rep(i,n) {
    cin >> a.at(i);
  }
  int ans = 0;
  sort(rng(a));
  rep(i,n) {
    int ai=a.at(i);
    int cai=a.at(i);
    if(hurui[ai]==INF) {
      ans--;
      hurui[ai]++;
      continue;
    }
    if(hurui[ai]>INF) continue;
    if(hurui[ai]>0 and hurui[ai] < 1000000) {
      continue;
    }
    hurui[ai] = INF;
    ans++;
    ai+=cai;
    while(ai<mx) {
      hurui[ai]++;
      ai+=cai;
    }
  }

  cout << ans << endl;


  return 0;
}
