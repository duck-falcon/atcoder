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
  int n,q;cin >> n >> q;
  vector<tuple<int,int,int>> kouzi(n,tuple<int,int,int>(-1,-1,-1));

  rep(i,n) {
    int s,t,x; cin >> s >> t >> x;
    // sort の都合でminusにしている
    kouzi.at(i) = (tuple<int,int,int>(x,-(x-s),-(x-t)));
  }
  sort(rng(kouzi));

  set<P> st;
  rep(i,q) {
    int d;cin >> d;
    st.insert(P(-d,i));
  }

  const int INF = 1001000101;
  // 工事に巻き込まれないと -1
  vi ans(q,-1);
  rep(i,n) {
    int x = get<0>(kouzi.at(i));
    int xs = -get<1>(kouzi.at(i));
    int xt = -get<2>(kouzi.at(i));
    while(true) {
      // (x-t,x-s]に対し、tより大きい削除されていない人間
      auto hidari = st.upper_bound(P(xt,INF));
      if(hidari==st.end()) break;
      // 工事に巻き込まれた
      if((*hidari).fi <= xs) {
        st.erase(hidari);
        ans.at((*hidari).se) = x;
      } else {
        break;
      }
    }
  }

  rep(i,q) cout << ans.at(i) << endl;


  return 0;
}
