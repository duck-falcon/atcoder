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

const int INF = 180100101;
vvi money(105,vi(105,INF));
vvi shima(105,vi());
int ans = -1;

bool isinv(vi acd,int to) {
  for(auto v : acd ) if(v == to) return true;
  return false;
}

void dfs(int from,int to,vi acd) {
  if(from == to) {
    acd.eb(to);
    int tmp=0;
    rep(i,acd.size() -1) {
      tmp+=money.at(acd.at(i)).at(acd.at(i+1));
    }
    ans=min(ans,tmp);
    return;
  }
  acd.eb(from);
  for(auto v : shima.at(from)) {
    if(isinv(acd,v)) continue;
    dfs(v,to,acd);
  }
  return;
}

int main() {
  int n,k;
  cin >> n >> k;
  vi ansvec;
  rep(i,k) {
    int t;
    cin >> t;
    if(t==0) {
      int from,to;
      cin >> from >> to;
      ans = INF;
      dfs(from,to,vi());
      if(ans==INF) ansvec.eb(-1);
      else ansvec.eb(ans);
    }
    if(t==1) {
      int from,to;
      cin >> from >> to;
      shima.at(from).eb(to);
      shima.at(to).eb(from);
      int e;cin >> e;
      money.at(from).at(to) = min(money.at(from).at(to),e);
      money.at(to).at(from) = min(money.at(to).at(from),e);
    }
  }
  for(auto v :ansvec) cout << v << endl;

  return 0;
}
