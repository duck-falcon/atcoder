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

int INF = 1001001001;

int main() {
  int d,g;
  cin >> d >> g;
  vector<int> p(d,0);
  vector<int> c(d,0);

  rep(i,d) cin >> p.at(i) >> c.at(i);

  int ans = INF;
  rep(i,1 << d) {
    int numg = 0;
    int numa = 0;
    for(int j = d - 1;j >= 0;j--) if(i>>j&1) {
      numg += c.at(j);
      numg += p.at(j) * (j+1) * 100;
      numa += p.at(j);
    }
    if(numg >= g) {
      ans = min(ans,numa);
    } else {
      for(int j = d - 1;j >= 0;j--) if((i>>j&1) == 0) {
        rep(k,p.at(j) - 1) {
          numg += ((j+1) * 100);
          numa += 1;
          if(numg >= g) {
            ans = min(ans,numa);
            break;
          }
        }
        if(numg >= g) {
          ans = min(ans,numa);
          break;
        }
      }
    }
  }

  cout << ans << endl;
  return 0;
}
