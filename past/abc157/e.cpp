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

int counta(string s) {
  set<char> st;
  int j = 0;
  rep(i,s.size()) {
    st.insert(s.at(i));
    j++;
    if(j%10000 == 0) {
      if ( st.size() == 26) break;
    }
  }
  return st.size();
}

int main() {
  int n,q;
  string s;
  cin >> n >> s >> q;
  vector<int> ans;
  rep(i,q) {
    int type;
    cin >> type;
    if(type == 1) {
      int p;cin >> p;
      char t;cin >> t;
      s.at(p-1) = t;
    } else {
      int l,r; cin >> l >> r;
      string t = s.substr(l-1,r-l+1);
      ans.emb(counta(t));
    }
  }
  rep(i,ans.size()) cout << ans.at(i) <<endl;

  return 0;
}
