#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n) ; ++i)
#define rrep(i,n) for(int i = 1; i < (n) ; ++i)
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define emb emplace_back
#define fcout cout << fixed << setprecision(15)
#define Yes(x) cout << ((x) ? "Yes" : "No") << endl;

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

char m[12][12];
bool r[12][12];
int shima;

void f(int x, int y) {
  if(m[x][y] == 'x') return;
  if(r[x][y]) return;
  r[x][y] = true;
  shima ++;
  f(x+1,y);
  f(x,y+1);
  f(x-1,y);
  f(x,y-1);
  return;
}

void rinit() {
  rep(i,12) rep(j,12) r[i][j] = false;
}

bool g(int x,int y,int num) {
  shima = 0;
  rinit();
  if(m[x][y] == 'x') {
    m[x][y] = 'o';
    f(x,y);
    if (shima == num + 1) {
       return true;
    }
    m[x][y] = 'x';
  }
  return false;
}

int main() {
  rep(i,12) rep(j,12) m[i][j] = 'x';
  int x = 0,y = 0;
  int num = 0;
  rrep(i,11) rrep(j,11) {
    cin >> m[i][j];
    if(m[i][j] == 'o') {
      num++;
      if(x == 0 and y == 0) {
      x = i; y = j;
      }
    }
  }

  f(x,y);
  if(shima == num) {
    cout << "YES" << endl;
    return 0;
  }

  bool flag = false;
  rrep(i,11) rrep(j,11) {
    flag |= g(i,j,num);
  }

  if(flag) cout << "YES" << endl;
  else cout << "NO" << endl;


  return 0;
}
