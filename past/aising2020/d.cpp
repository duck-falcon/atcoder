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


int mx = 0;
int px=0;

vi vx;
vi modcp;
vi modcm;
int n;

void f(int count,int j) {
  if(count==1) {
    if(vx.at(n - j)) {
      cout << 0 << endl;
      return;
    }
  }
  int ans = 0;
  int x = 0;
  if(vx.at(n - j)) {
    x = mx - modcm.at(n-j);
    x%=count-1;
    if(x<0) x+= count-1;
  }
  else {
    x = px + modcp.at(n-j);
    x %= count+1;
  }
  ans++;

  while(x!=0) {
    x = x % __builtin_popcount(x);
    ans++;
  }
 cout << ans << endl;
}


int main() {
  cin >> n;
  string s; cin >> s;
  int count = 0;
  rep(i,n) {
    if(s.at(i)=='1') {
      vx.eb(1);
      count++;
    } else vx.eb(0);
  }
  if(count == 0) {
    rep(i,n) cout << 1 << endl;
    return 0;
  }
  reverse(rng(vx));

  int t = 1 % (count+1);

  rep(i,n) {
    modcp.eb(t);
    t = t << 1;
    t %= count+1;
  }
  rep(i,n) {
    if(vx.at(i)) {
      px+=modcp.at(i)%(count+1);
      px%=count+1;
    }
  }

  if(count!=1) {
    t = 1 % (count -1);
    rep(i,n) {
      modcm.eb(t);
      t = t << 1;
      t %= count-1;
    }
    rep(i,n) {
      if(vx.at(i)) {
        mx+=modcm.at(i)%(count-1);
        mx%=(count-1);
      }
    }
  }

  rep(i,n) f(count,i+1);

  return 0;
}
