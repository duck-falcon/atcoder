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
using P = pair<ll,ll>;

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
  ll x,y,a,b,c;
  cin >> x >> y >> a >> b >> c;

  vector<ll> p(a,0);
  rep(i,a) cin >> p.at(i);
  vector<ll> q(b,0);
  rep(i,b) cin >> q.at(i);
  vector<ll> r(c,0);
  rep(i,c) cin >> r.at(i);

  sort(all(p),greater<ll>());
  sort(all(q),greater<ll>());
  sort(all(r),greater<ll>());

  priority_queue<ll, std::vector<ll>, std::greater<ll> > pq;
  priority_queue<ll, std::vector<ll>, std::greater<ll> > qq;
  ll ptot = 0;
  ll qtot = 0;
  rep(i,x) {
    pq.push(p.at(i));
    ptot += p.at(i);
  }
  rep(i,y) {
    qq.push(q.at(i));
    qtot += q.at(i);
  }

  rep(i,min(x+y,c)){
    if(pq.top() <= qq.top())
    {
      if(r.at(i) > pq.top()) {
        ptot -= pq.top();
        pq.pop();
        pq.push(r.at(i));
        ptot += r.at(i);
      }
    } else {
      if(r.at(i) > qq.top()) {
        qtot -= qq.top();
        qq.pop();
        qq.push(r.at(i));
        qtot += r.at(i);
      }
    }
  }

  cout << ptot + qtot << endl;

  return 0;
}
