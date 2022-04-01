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

int r,s,p;

int j(char a,char b) {
  if(a=='r' and b=='s') return r;
  if(a=='s' and b=='p') return s;
  if(a=='p' and b=='r') return p;
  return 0;
}

int sc(char a) {
  if(a=='r' ) return r;
  if(a=='s' ) return s;
  if(a=='p') return p;
  return 0;
}

char win_to(char a) {
  if(a=='r') return 'p';
  if(a=='s') return 'r';
  if(a=='p') return 's';
  return 'a';
}

string remain(char a) {
  if(a=='r') return "sp";
  if(a=='s') return "rp";
  if(a=='p') return "sr";
  return "aa";
}

bool f (string a,char b) {
  for(auto v : a) if(v==b)return true;
  return false;
}

int main() {
  int n,k;
  cin >> n >> k >> r >> s >> p;
  string t;
  cin >> t;
  ll ans=0;
  string h="rsp";

  rep(i,k) {
    string rem = h;
    rep(j,n/k + 1) {
      if(i+j*k >= n) continue;
      int now = i+j*k;
      char yh = t.at(now);
      if(f(rem,win_to(yh))) {
        ans+=sc(win_to(yh));
        rem=remain(win_to(yh));
      } else {
        if(now+k<n) {
          char yhs=t.at(now+k);
          rem=remain(yhs);
        }
      }
    }
  }


  cout << ans << endl;

  return 0;
}
