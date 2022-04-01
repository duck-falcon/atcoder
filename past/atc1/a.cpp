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

int r[502][502];
char p[502][502];

void s(int x,int y) {
  if(p[x][y] == '#') return;
  if(r[x][y]) return;
  r[x][y] = 1;

  s(x+1,y);
  s(x,y+1);
  s(x-1,y);
  s(x,y-1);
  return;
}

int main() {
  rep(i,502) rep(j,502) p[i][j] = '#';

  int h,w;
  cin >> h >> w;
  int xs,ys,xg,yg;
  rep(i,h) rep(j,w) {
    cin >> p[i][j];
    if(p[i][j] == 's') {
      xs = i; ys = j;
    } else if (p[i][j] == 'g') {
      xg = i,yg = j;
    }
  }

  s(xs,ys);
  cout << (r[xg][yg] ? "Yes" : "No") << endl;
  if(r[xg][yg]) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
