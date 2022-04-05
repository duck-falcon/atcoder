#include <bits/stdc++.h>
#define rrep(i,n) for(int i = 1; i < (n) ; ++i)
#define rep(i,n) for(int i = 0; i < (n) ; ++i)
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define emb emplace_back
#define fcout cout << fixed << setprecision(15)


using namespace std;
using ll = long long;
using P = pair<int,int>;

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
vector<int> route;
vector<vector<int>> v(102,vector<int>());
vector<bool> r(102,false);
int res;
vector<bool> d(102,true);

void f(int x,int g,int before) {
  if(!d.at(x)) return;
  if(v.at(x).size() == 0) return;
  if(r.at(x) and x == g) {
    rep(i,route.size()) d.at(route.at(i)) = false;
    route = {};
    return;
  };
  if(r.at(x)) return;
  route.emb(x);
  r.at(x) = true;
  rep(j,v.at(x).size()) {
    if(before != v.at(x).at(j)) f(v.at(x).at(j),g,x);
  }
  return;
}

void rinit() {
  rep(i,102) r.at(i) = false;
}

void g(int x) {
  if(!d.at(x)) return;
  r.at(x) = true;
  d.at(x) = false;
  if(v.at(x).size() == 0) {
    res++;
    return;
  }
  route.emb(x);
  rep(i,v.at(x).size()) {
    g(v.at(x).at(i));
  }
  return;
}

int main() {
  int n,m;
  cin >> n >> m;
  rep(i,m) {
    int x,y;
    cin >> x >> y;
    v.at(x).emb(y);
    v.at(y).emb(x);
  }

  rrep(i,n+1) {
    route = {};
    rinit();
    f(i,i,-1);
  }

  rrep(i,n+1) {
    rinit();
    g(i);
    if(route.size() > 0) {
      route = {};
      res++;
    }
  }

  cout << res << endl;
  return 0;
}
