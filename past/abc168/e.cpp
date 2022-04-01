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

template<typename T>
void pp(pair<T,T> pair) {
    cout << "<" << pair.fi << ","<< pair.se << ">";
}

template<typename T> void pv2(vector<vector<T>> vec) {
  for(auto& v : vec) pv(v);
}
// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1000000007;

struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

// a > 0, b > 0
ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a; }
// a > 0, b > 0, a*b << ll
ll lcm(ll a, ll b) { return a*b/gcd(a,b); }

int main() {
  int n;
  cin >> n;
  map<pair<ll,ll>,P> mp;
  mint zero=mint(0);
  rep(i,n) {
    ll a,b;
    cin >> a >> b;
    if(a==0 and b==0) {
      zero+=1;
      continue;
    }
    if(a==0) {
      if(mp.find(pair<ll,ll>(0,0))!=mp.end()) {
        mp[pair<ll,ll>(0,0)].fi+=1;
      } else {
        mp[pair<ll,ll>(0,0)] = P(1,0);
      }
      continue;
    } else if(b==0) {
      if(mp.find(pair<ll,ll>(0,0))!=mp.end()) {
        mp[pair<ll,ll>(0,0)].se+=1;
      } else {
        mp[pair<ll,ll>(0,0)] = P(0,1);
      }
      continue;
    }
    ll c = gcd(a,b);
    a/=c;
    b/=c;
    if(a>0 and b>0) {
      if(mp.find(pair<ll,ll>(a,b))!=mp.end()) mp[pair<ll,ll>(a,b)].fi+=1;
      else mp[pair<ll,ll>(a,b)]=P(1,0);
    } else {
      ll aa = abs(a);ll bb = abs(b);
      if(mp.find(pair<ll,ll>(bb,aa))!=mp.end()) mp[pair<ll,ll>(bb,aa)].se+=1;
      else mp[pair<ll,ll>(bb,aa)]=P(0,1);
    }
  }
  mint ans=1;
  mint two=mint(2);
  for(auto x : mp) {
    ll mi = x.se.se;
    ll pu = x.se.fi;
    mint tans=mint(0);
    tans+=(two.pow(mi)-1);
    tans+=(two.pow(pu)-1);
    tans+=1;
    ans*=tans;
  }

  cout << ans -1 + zero << endl;

  return 0;
}
