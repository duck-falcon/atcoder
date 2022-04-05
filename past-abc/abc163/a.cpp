#include <bits/stdc++.h>
#define rep(i,n)    for(int i = 0; i < (n) ; ++i)
#define orep(i,n)   for(int i = 1; i <= (n); ++i)   // one rep
#define drep(i,n)   for(int i = (n)-1; i >= 0; --i) // down rep
#define srep(i,s,t) for(int i = (s); i < (t); ++i)  // set rep
#define rng(x)  (x).begin(),(x).end()   // range
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

int main() {
  int r;
  cin >> r;
  float p = 3.141592;
  fcout << 2 * p * r << endl;

  return 0;
}
