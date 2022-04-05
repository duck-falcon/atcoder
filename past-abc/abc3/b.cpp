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

string mozi="atcoder@";
bool f(char a) {
  bool flag=false;
  rep(i,mozi.size()) if(a == mozi.at(i)) flag = true;
  return flag;
}

int main() {
  string s,t;cin >> s >> t;

  bool flag=true;
  rep(i,s.size()) {
    if(s.at(i)=='@') {
      flag&=f(t.at(i));
    }
    if(t.at(i)=='@') {
      flag&=f(s.at(i));
    }
    if(s.at(i) != '@' and t.at(i) != '@' and s.at(i)!=t.at(i)) flag=false;
  }

  if(flag) {
    cout << "You can win" << endl;
  } else {
    cout << "You will lose" << endl;
  }

  return 0;
}
