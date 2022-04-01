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

bool f(P a, P b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

int main() {
  int n;
  cin >> n;
  vp r(n,P(0,0));
  rep(i,n) {
    int x,y;cin >> x >> y;
    r.at(i)=(P(x,y));
  }
  vp b(n,P(0,0));
  rep(i,n) {
    int x,y;cin >> x >> y;
    b.at(i) = P(x,y);
  }

  sort(rng(b));
  sort(rrng(r),f);

  vi rp(n,1);
  int ans = 0;
  rep(i,n) {
    int bx,by;
    bx=b.at(i).fi;by=b.at(i).se;
    rep(j,n) {
      if(rp.at(j)) {
        int rx,ry;
        rx=r.at(j).fi;ry=r.at(j).se;
        if(rx < bx and ry < by) {
          ans++;
          rp.at(j)=0;
          break;
        }
      }
    }
  }
  cout << ans << endl;

  return 0;
}
