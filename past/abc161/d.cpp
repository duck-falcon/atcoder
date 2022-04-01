#include <bits/stdc++.h>
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

bool lun(ll n) {
  vector<int> b;
  ll m = n;
  while(true){
    b.emb(m%10);
    m /= 10;
    if(m==0) break;
  }
  rep(i,b.size()) {
    if(i == b.size() - 1) break;
    if(abs(b.at(i)-b.at(i+1)) > 1) return false;
  }
  return true;
}

int main() {
  int k;
  //cin >> k;

  vector<ll> a;
  int num = 0;
  ll i = 1;
  while(num <= 100005) {
    if(lun(i)) {
      a.emb(i);
      num++;
    }
    i++;
  }

  pv(a);

  return 0;
}
