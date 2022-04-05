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
  ll n;
  cin >> n;
  vi k;
  int m=0;
  orep(i,50) {
    m+=i;
    k.eb(m);
  }
  int ans=0;
  if(n==1) {
    cout << 0 << endl;
    return 0;
  }
  bool flag = false;
  orep(i,1200001) {
    if(i==1) continue;
    int tmp=0;
    while(n%i==0) {
      n /= i;
      tmp++;
      flag = true;
    }

    int jj;
    if(tmp==0) continue;
     rep(j,50) if(tmp>=k.at(j)) {
       jj=j;
     }
     ans+=(jj+1);
  }
  if(n!=1) ans++;
  if(flag) cout << ans << endl;
  else cout << 1 << endl;

  return 0;
}
