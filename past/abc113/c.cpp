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

int nken=1;
int nban=1;

string roku(int a) {
  string ans = to_string(a);
  while(ans.size()!=6) {
    ans.insert(0,"0");
  }
  return ans;
}
string setNumber(P pa) {
  int k = pa.fi;int y=pa.se;
  if(nken<k) {
    nken=k;
    nban=1;
  }
  string mae=roku(nken);
  string ushiro=roku(nban);
  nban++;
  return mae+ushiro;
}

int main() {
  int n,m;
  cin >> n >> m;
  vp nst;
  vp st;
  rep(i,m) {
    int ken,year;
    cin >> ken >> year;
    st.eb(P(ken,year));
  }
  nst=st;
  sort(rng(st));
  map<P,string> mp;
  rep(i,st.size()) {
    mp[st.at(i)]=setNumber(st.at(i));
  }

  rep(i,nst.size()) {
    cout << mp[nst.at(i)] << endl;
  }

  return 0;
}
