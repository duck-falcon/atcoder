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

vvi tako(101,vi(101,0));
int n;
int countmx(P pair) {
  int mx=0;
  rep(i,n) rep(j,n) {
    int t=0;
    if(i+pair.fi-1 < n and j+pair.se-1<n) {
      srep(ii,i,i+pair.fi) srep(jj,j,j+pair.se) {
        t+=tako.at(ii).at(jj);
      }
      mx=max(t,mx);
    }
    t=0;
    if(i+pair.se-1 < n and j+pair.fi-1<n) {
      srep(ii,i,i+pair.se) srep(jj,j,j+pair.fi) {
        t+=tako.at(ii).at(jj);
      }
      mx=max(t,mx);
    }

  }
  return mx;
}

vp bunkai(int m) {
  vp ans;
  orep(i,(int)sqrt(m)) {
    if(m%i==0) ans.eb(P(i,m/i));
  }
  return ans;
}

int main() {
  cin >> n;
  rep(i,n) rep(j,n){
    cin >> tako.at(i).at(j);
  }
  vi ans(n*n+1,0);
  int nowmax=0;
  orep(i,n*n) {
    vp bun = bunkai(i);
    int mx = 0;
    rep(i,bun.size()) {
      mx=max(mx,countmx(bun.at(i)));
    }
    nowmax=max(mx,nowmax);
    ans.at(i) = nowmax;
  }

  int q;
  cin >> q;
  rep(i,q) {
    int m;
    cin >> m;
    cout << ans.at(m) << endl;
  }

  return 0;
}
