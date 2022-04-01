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
  int n,l;
  cin >> n >> l;
  string dummy;
  getline(cin,dummy);
  vector<string> yoko(l);
  string maru;
  rep(i,l) {
    getline(cin,yoko.at(i));
  }
  getline(cin,maru);

  int start;
  int t=0;
  while(t!=maru.size()){
    if(maru.at(t)=='o') start = t/2+1;
    t++;
  }

  vvi amida(l,vi(n));
  rep(j,l) {
    rep(i,2*n-1) {
      if(yoko.at(j).at(i)=='-') amida.at(j).at(i/2)=1;
    }
  }

  reverse(rng(amida));
  rep(i,l) {
    if(amida.at(i).at(start-1)) {
      start+=1;
      continue;
    }
    if(start-2<0) continue;
    if(amida.at(i).at(start-2)) start-=1;
  }

  cout << start << endl;
  return 0;
}
