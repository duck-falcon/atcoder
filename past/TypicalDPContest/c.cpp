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
#define double long double
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
  for(auto& v : vec) { fcout << v << ","; }
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

vector<int> r(1<<10,0);

vector<double> f(vector<double> &x,vector<double> &y,int n,int st) {
  vector<double> ans(n << 1,0);
  int k = 0;
  rep(i,n) {
      rep(j,n) {
        double t = x.at(i) * y.at(j);
        double tt = 1.0/(1.0+powl(10,(r.at(j+n+st)-r.at(i+st))/400.0));
        ans.at(k) += t*tt;
    }
  k++;
  }

  rep(i,n) {
      rep(j,n) {
      double t = y.at(i) * x.at(j);
      double tt = 1.0/(1.0+powl(10,(r.at(j+st)-r.at(i+n+st))/400.0));
      ans.at(k) += t*tt;
    }
  k++;
  }
  return ans;
}


int main() {
  int k;cin >> k;

  queue<vector<double>> que;
  rep(i,1<<k) {
    cin >> r.at(i);
  }

  vector<double> a(1,1.0);
  vector<double> b(1,1.0);
  int st = 0;
  rep(i,1<<(k-1)) {
    que.push(f(a,b,1,st));
    st+=2;
  }

  vector<double> ans;
  int n = 2;
  st = -4;
  while(true) {
    vector<double> x = que.front();que.pop();
    if(x.size() == n) st += 2 * n;
    else {
      st = 0;
      n = x.size();
    }
    if(n == (1 << (k))) {
      ans.swap(x);
      break;
    }
    vector<double> y = que.front();que.pop();
    que.push(f(x,y,n,st));
  }

  rep(i,ans.size()) fcout << ans.at(i) << endl;


  return 0;
}
