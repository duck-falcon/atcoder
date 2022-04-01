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

char itoc(int a) {
  if(a==0) return '0';
  if(a==1) return '1';
  if(a==2) return '2';
  if(a==3) return '3';
  if(a==4) return '4';
  if(a==5) return '5';
  if(a==6) return '6';
  if(a==7) return '7';
  if(a==8) return '8';
  if(a==9) return '9';
  return 'e';
}

const int h = 3600;
const int m = 60;

string hutaketa(int a) {
  int ten = a / 10;
  int one = a - ten * 10;
  string ans = "";

  ans+=itoc(ten);
  ans+=itoc(one);
  return ans;
}

int main() {
  int n;cin >> n;
  cout << hutaketa(n / h) << ":" << hutaketa((n % h) / m) << ":" << hutaketa(n % m) << endl;

  return 0;
}
