#include <bits/stdc++.h>
using namespace std;
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
#define fcout cout << fixed << setprecision(15)

using ll  = long long;
using P   = pair<int,int>;
using vi  = vector<int>;
using vvi = vector<vi>;
using vp  = vector<P>;
using vvp = vector<vp>;
using vl  = vector<ll>;
using rpq = priority_queue<int,vi,less<int>>;   // 大きい順
using pq  = priority_queue<int,vi,greater<int>>;// 小さい順

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

template<typename T> void pv2(vector<vector<T>> vec) {
  for(auto& v : vec) pv(v);
} 

const double INF = 1000100101;
const double PI = 3.14159265358979323846264338327950288;

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a; }

int main() {
  int n; cin >> n;
  vp p(n,P(0,0));
  rep(i,n) {
    int x,y; cin >> x >> y;
    p.at(i) = P(x,y);
  }
  
  double ans = 0.0;
  rep(i, n) {
    int nx = p.at(i).fi;int ny = p.at(i).se;
    double min1 = INF+1, max2 = -INF-1, min3 = INF+1, max4 = -INF-1;
    double max1 = -1, min2 = 1, max3 = -1, min4 = 1;
    cout << "---------min max-------" << endl;
    cout << min1 << " " << max1 << endl;
    cout << min2 << " " << max2 << endl;
    cout << min3 << " " << max3 << endl;
    cout << min4 << " " << max4 << endl;
    unordered_map<ll, int> mp;
    cout << "nx: " << nx << " ny: " << ny << endl;
    rep(j,n) {
      if(i==j) continue;
      int x = p.at(j).fi;int y = p.at(j).se;
      cout << "x: " << x << " y: " << y << endl;
      if(x == nx) {
        if(y > ny) {
          min1 = min(min1, INF);
          max1 = INF;
          max2 = min(max2, -INF);
          min2 = -INF;
        }
        if(y < ny) {
          min3 = min(min3, INF);
          max3 = INF;
          max4 = max(max4, -INF);
          min4 = -INF;
        }
      }
      int c = gcd(x-nx, y-ny);
      int cx = (x-nx) / c;int cy = (y-ny) /c;
      ll b = cx * 1000000000 + cy;
      if(mp[b] == 2) {
        ans = 180;
        break;
      }
      mp[b] += 1;
      // 2点の傾き
      double a = (double) cy / cx;
      cout << "a " << a << endl;
      if(x >= nx and y >= ny) {
        min1 = min(a, min1);
        max1 = max(a, max1);
      } else if(x <= nx and y >= ny) {
        max2 = max(a, max2);
        min2 = min(a, min2);
      } else if (x <= nx and y <= ny) {
        min3 = min(a, min3);
        max3 = max(a, max3);
      } else if(x >= nx and y <= ny) {
        max4 = max(a, max4);
        min4 = min(a, min4);
      }
    }
    cout << "---------min max-------" << endl;
    cout << min1 << " " << max1 << endl;
    cout << min2 << " " << max2 << endl;
    cout << min3 << " " << max3 << endl;
    cout << min4 << " " << max4 << endl;
    double theta = 0.0;
    if(min1 != INF+1 and max2 != -INF-1) theta = (PI + atan(max2) - atan(min1)) * 180 / PI;
    else if(min3 != INF + 1 and max4 != -INF-1) theta = (PI - atan(min3) + atan(max4)) * 180 / PI;
    else if(max1 != -1 and min4 != 1) theta = (-atan(min4) + atan(max1)) * 180 / PI;
    else if(max3 != -1 and min2 != 1) theta = (atan(max3) - atan(min2)) * 180 / PI;
    
    ans = max(theta, ans);
  }

  fcout << ans << endl;

  return 0;
}
