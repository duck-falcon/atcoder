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
  int m;
  cin >> m;
  vp star(m,P(0,0));
  P sbase = P(0,0);
  cin >> sbase.fi >> sbase.se;
  star.at(0) = sbase;
  srep(i,1,m) {
    cin >> star.at(i).fi >> star.at(i).se;
  }

  int n;
  cin >> n;
  vp pic(n,P(0,0));
  rep(i,n) cin >> pic.at(i).fi >> pic.at(i).se;

  rep(i,n) {
    P pbase = pic.at(i);
    P dif = P(sbase.fi-pbase.fi,sbase.se-pbase.se);
    vi stari(m,0);
    rep(j,n) {
      P pt=P(pic.at(j).fi+dif.fi,pic.at(j).se+dif.se);
      rep(k,m) if(pt.fi == star.at(k).fi and pt.se == star.at(k).se) {
        stari.at(k)=1;
        break;
      }
    }
    bool flag = true;
    rep(k,m) if(stari.at(k)!=1) flag=false;
    if(flag) {
      cout << - dif.fi << " " << - dif.se << endl;
      break;
    }
  }

  return 0;
}
