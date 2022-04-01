#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n) ; ++i)
#define drep(i,n) for(int i = (n) -1;i>=0;--i)
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

int main() {
  int n;
  cin >> n;
  vector<int> a(n,0);
  rep(i,n) cin >> a[i];

  sort(all(a));
  int res=0;
  bool alice=true;
  drep(i,n) {
    if(alice) {
      res+=a[i];
      alice=false;
    } else {
      res-=a[i];
      alice=true;
    }
  }

  cout << res << endl;

  return 0;
}
