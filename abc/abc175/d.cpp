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

const ll INF = 1000000000000000000;
ll f(int a,vi &c ,vi &p) {
  ll ans = - INF;
  if(a==0) return 0;
  orep(ika,a) {
    orep(s,c.size()) {
      ll tmp = 0;
      int nagasa = 0;
      int start = s;
      while(nagasa < ika) {
        tmp += c.at(start-1);
        start = p.at(start-1);
        nagasa++;
      }
      ans = max(ans,tmp);
    }
    cout << ika << endl;
    cout << ans << endl;
  }
  return ans;
}

vector<pair<int,vector<int>>> loop(vi &c,vi&p) {
  vi loopcheck(c.size(),0);
  vector<pair<int,vi>> ansvec;
  ll ans = - INF;
    orep(s,c.size()) {
      ll tmp = 0;
      int start = s;
      vi z;
      z.eb(s-1);
      int nagasa = 0;
      if(loopcheck.at(s-1)) continue;
      loopcheck.at(s-1)++;
      while(true) {
        tmp += c.at(start-1);
        start = p.at(start-1);
        z.eb(start-1);
        nagasa++;
        if(start-1 == s) break;
      }
      ansvec.push_back(pair<int,vector<int>>(nagasa,z));
    }
  return ansvec;
}

int main() {
  int n,k;cin >> n >> k;
  vi p(n,0);
  rep(i,n) cin >> p.at(i);
  vi c(n,0);
  ll sm = 0;
  int start = 0;
  rep(i,n) {
    cin >> c.at(i);
  }
  vector<pair<int,vi>> loopvec = loop(c,p);
  sort(rrng(loopvec));
  rep(i,loopvec.size()) {
    if(loopvec.at(i).fi <= k) {
      rep(j,loopvec.at(i).se.size()) {
        sm+=loopvec.at(i).se[j];
      }
    }
  }

  ll score = 0;
  if(sm > 0) {
    score += sm * (k / n);
    cout << score << endl;
    score += f(k % n,c,p);
  } else {
    score += f(n,c,p);
  }

  cout << score << endl;


  return 0;
}
