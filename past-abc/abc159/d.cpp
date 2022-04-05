#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n) ; ++i)
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define emb emplace_back

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

int main() {
  int n;
  cin >> n;
  vector<ll> a(n,0);
  vector<ll> s(n+1,0);
  rep(i,n) {
    cin >> a.at(i);
    s.at(a.at(i)) += 1;
  }

  ll ssum = 0;
  rep(i,n+1) {
    ssum += (s.at(i)) * (s.at(i)-1)/2;
  }
  rep(i,n) {
    cout << ssum + ((s.at(a.at(i)) - 1) * (s.at(a.at(i))-2)/2) - ((s.at(a.at(i))) * (s.at(a.at(i))-1)/2)<< endl;
  }



  return 0;
}
