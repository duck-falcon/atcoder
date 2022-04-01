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


mint dp[103][15];
int calc[9][2];

int main() {
  dp[0][1] = mint(1);
  int h,w,k;
  cin >> h >> w >> k;

  rep(i,9) {
    if(i==0 or i == 1) {
      calc[i][0]=1;
      continue;
    }
    int now=i-1;
    int ans=0;
    rep(j,1<<now){
      bool flag=false;
      bool flag2=true;
      rep(kk,now) {
        if(j>>kk&1) {
          if(flag) {
            flag2=false;
            break;
          }
          flag=true;
        } else {
          flag=false;
        }
      }
      if(flag2)ans++;
    }
    calc[i][0]=ans;
  }

  rep(i,9) {
    if(i==0 or i == 1) {
      calc[i][1]=1;
      continue;
    }
    int now=i-1;
    int ans=0;
    rep(j,1<<now){
      bool flag=true;
      bool flag2=true;
      rep(kk,now) {
        if(j>>kk&1) {
          if(flag) {
            flag2=false;
            break;
          }
          flag=true;
        } else {
          flag=false;
        }
      }
      if(flag2)ans++;
    }
    calc[i][1]=ans;
  }

  rep(i,h){
    orep(j,w) {
      if(j==1) {
        dp[i+1][1]+=dp[i][1]*calc[w-1][0];
        dp[i+1][2]+=dp[i][1]*calc[w-1][1];
      }
      else if(j==w) {
        dp[i+1][w]+=dp[i][w]*calc[w-1][0];
        dp[i+1][w-1]+=dp[i][w]*calc[w-1][1];
      } else {
        dp[i+1][j] += dp[i][j]*calc[j-1][0]*calc[w-j][0];
        dp[i+1][j-1] += dp[i][j]*calc[j-1][1]*calc[w-j][0];
        dp[i+1][j+1] += dp[i][j]*calc[j-1][0]*calc[w-j][1];
      }
    }
  }
  cout << dp[h][k] << endl;
  return 0;
}
