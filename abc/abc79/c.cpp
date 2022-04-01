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

int main() {
  string s;
  cin >> s;
  vector<int> a(4,0);
  rep(i,4) a.at(i) = s.at(i) - '0';

  int res;
  rep(i,1<<3) {
    res = a.at(0);
    rep(j,3) {
      if(i>>j&1) res+=a.at(j+1);
      else res -= a.at(j+1);
    }
    if(res == 7) {
      string t=to_string(a.at(0));
      rep(j,3) {
        if(i>>j&1) t=t+"+"+to_string(a.at(j+1));
        else t=t+"-"+to_string(a.at(j+1));
      }
      t+="=7";
      cout << t << endl;
      break;
    }
  }

  return 0;
}
