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

template<>
void pv(vector<pair<ll,int>> vec) {
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

  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

int main() {
  int n,k;
  cin >> n >> k;
  vector<pair<ll,int>> v;

  rep(i,n) {
    ll a ; cin >> a;
    if(a>=0) v.eb(pair<ll,int>(a,1));
    if(a<0) v.eb(pair<ll,int>(-a,0));
  }
  sort(rrng(v));

  mint ans=mint(1);
  int mp = 0;

  rep(i,k) {
    if(v.at(i).se == 0) mp++;
    ans*=mint(v.at(i).fi);
  }
  if(mp%2 != 0) {
    int plmi = v.at(k-1).se;
    ll kouho1=v.at(k-1).fi;
    if(kouho1==0) {
      cout << 0 << endl;
      return 0;
    }
    ll louho1=0;
    bool plmiflag = false;
    // last plus or last minus
      srep(i,k,n) {
        if(v.at(i).se == !plmi) {
          louho1=v.at(i).fi;
          plmiflag = true;
          break;
        }
     }
     ll kouho2=0,louho2=0;
     bool nazoflag=false;
     drep(i,k) {
       if(v.at(i).se==!plmi) {
         kouho2=v.at(i).fi;
         nazoflag=true;
         break;
       }
     }
     srep(i,k,n) {
       if(!nazoflag) continue;
       if(v.at(i).se == plmi) {
         louho2=v.at(i).fi;
         plmiflag = true;
         break;
       }
     }
     if(plmiflag) {
       if(louho2*kouho1<=louho1*kouho2) {
         ans/=mint(kouho1);
         ans*=mint(louho1);
       } else {
         ans/=mint(kouho2);
         ans*=mint(louho2);
       }
     }
     else {
       ans=mint(1);
       sort(rng(v));
       rep(i,k) {
         ans*=mint(v.at(i).fi);
       }
       ans=-ans;
    }
  }

  cout << ans << endl;

  return 0;
}
