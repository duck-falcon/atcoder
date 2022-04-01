#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n) ; ++i)
#define srep(i,a,b) for(int i = (a); i < (b); ++i)
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define emb emplace_back
#define fcout cout << fixed << setprecision(15)

using namespace std;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;

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

bool dpk[100005];

int main() {
  int n,k;
  cin >> n >> k;
  vi a(n,0);
  int mn=100000001;
  rep(i,n) {
    cin >> a.at(i);
    mn=min(a.at(i),mn);
  }
  rep(i,n) {
    dpk[a.at(i)] = 1;
  }
  srep(i,mn,k+1) {
    if(dpk[i]) continue;
    rep(j,n) {
      if(i-a.at(j)<0) continue;
      if(!dpk[i-a.at(j)]) dpk[i]=true;
    }
  }

  if(dpk[k]) cout << "First" << endl;
  else cout << "Second" << endl;

  return 0;
}
