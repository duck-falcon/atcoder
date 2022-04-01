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

const int mod = 1000000007;
// const int mod = 998244353;

struct mint {
  long long x;
  mint(long long x = 0) : x((x%mod+mod)%mod) {}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if((x -= a.x) < 0) x += mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint operator++() const { return mint(*this) += mint(1);}
  mint operator--() const { return mint(*this) -= mint(1);}
  mint pow(long long t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
  mint pow(mint t) const {
    if (!t.x) return 1;
    mint a = pow(t.x>>1);
    a *= a;
    if (t.x&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

int main() {
  int h,w;cin >> h >> w;
  vvi maze(h,vi(w,0));
  mint ans = mint(0);
  int k = 0;

  rep(i,h) {
    string s; cin >> s;
    rep(j,w) {
      if(s.at(j)=='.') {
        maze.at(i).at(j) = 1;
        k++;
      }
      else {
        maze.at(i).at(j) =0;
      }
    }
  }

  rep(i,h) {
    bool flag = false;
    mint tans = mint(0);
    rep(j,w) {
      if(maze.at(i).at(j)==1){
        if(flag) tans+=mint(1);
        flag=true;
      } else {
        ans+=(mint(2).pow(tans)-mint(1))*mint(2).pow(mint(k)-tans);
        tans=0;
        flag=false;
      }
  }
}

  rep(i,w) {
    bool flag = false;
    mint tans = mint(0);
    rep(j,h) {
      if(maze.at(j).at(i)==1){
        if(flag) tans+=mint(1);
        flag=true;
      } else {
        ans+=(mint(2).pow(tans)-mint(1))*mint(2).pow(mint(k)-tans);
        tans=0;
        flag=false;
      }
  }
}

cout << ans << endl;

  return 0;
}
