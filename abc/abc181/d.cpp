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

int co(vi b) {
  int ans = 0;
  rep(i,b.size()) {
    if(i==0) continue;
    ans += b.at(i);
  }
  return ans;
}

bool f(vi a,vi b) {
  if(b.at(0)>0) return false;
  orep(i,9) {
    if(a.at(i)-b.at(i) < 0) return false;
  }
  if(co(b)==2 or co(b)==1) {
    orep(i,9) {
      if(a.at(i)!=b.at(i)) return false;
    }
  }
  return true;
}

int main() {
  string s;cin >> s;
  vi a(10,0);
  rep(i,s.size()) {
    a.at(s.at(i)-'0')++;
  }

  bool flag=false;

  orep(i,124) {
    vi b(10,0);
    int t = i * 8;
    b.at(t%10)++;
    if(t>10) b.at((t/10)%10)++;
    if(t>100)b.at((t/100)%10)++;
    if(f(a,b)) {
      flag = true;
      break;
    }
  }

  Yes(flag);

  return 0;
}
