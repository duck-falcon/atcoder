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



char p(char c) {
  vector<char> v={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  if(c=='z') return 'a';
  rep(i,26) {
    if(c == v.at(i)) return v.at(i+1);
  }
}

int main() {
  ll n;
  cin >> n;
  ll tmp = n;
  ll i = 26;
  int mozisuu = 1;
  while(true) {
    tmp -= i;
    if(tmp <= 0) break;
    else n -= i;
    i *= 26;
    mozisuu += 1;
  }

  i = i/26;
  string ans="";
  rep(i,mozisuu) ans+='a';
  n--;

  int now = 0;
  while(true) {
    if(n - i >= 0) {
      ans.at(now) = p(ans.at(now));
      n -= i;
    } else if(n != 0) {
      i /= 26;
      now+=1;
    } else {
      break;
    }
  }

  cout << ans << endl;

  return 0;
}
