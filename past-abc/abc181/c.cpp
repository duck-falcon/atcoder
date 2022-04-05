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

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a; }

int main() {
  int n;cin >> n;
  vp z(n,P(0,0));

  rep(i,n) {
    int x,y;
    cin >> x >> y;
    z.at(i) = P(x,y);
  }

  bool flag = false;

  int c;
  int a,b;
  rep(i,n) {
    map<P,bool> mp;
    rep(j,n) {
      if(i==j) continue;
      a = z.at(i).fi - z.at(j).fi;
      b = z.at(i).se - z.at(j).se;
      if(a < 0 and b < 0) {
        a = -a;
        b = -b;
      } else if (a<0 and b> 0) {
        a = -a;
        b = -b;
      } else if(a == 0 and b == 0) {
        a = 0;b=0;
      }
      else if (a==0) {
        b=1;
      } else if(b==0) {
        a=1;
      }
      if(a==0 or b == 0) c = 1;
      else c = gcd(a,b);
      if(mp.count(P(a/c,b/c)) == 1) {
        flag=true;
        break;
      }
      mp[P(a/c,b/c)] = true;
    }
  }

  Yes(flag);

  return 0;
}
