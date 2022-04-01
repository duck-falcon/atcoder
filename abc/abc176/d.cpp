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

vector<vector<int>> maze;
vector<vector<int>> seen;
vector<vector<int>> new_place;
vector<vector<int>> tmp_new_place;
int h,w;
bool flag = true;

vector<int> dx = {1,0,-1,0}, dy = {0,1,0,-1};
vector<pair<int,int>> path;
queue<vector<pair<int,int>>> que;
int loop = 0;

void dfs_seen(int x, int y) {
  if(seen.at(x).at(y)) return;
  seen.at(x).at(y) = 1;
  path.push_back(pair<int,int>(x,y));
  rep(i,dx.size()) {
    int nx = x + dx.at(i),ny = y + dy.at(i);
    if(isin(nx,0,h) and isin(ny,0,w) and !seen.at(nx).at(ny) and maze.at(nx).at(ny)) {
       dfs_seen(nx,ny);
     }
  }
}

vector<int> dxn = {1,-1,-1,1,2,2,2,1,0,-1,-2,-2,-2,-2,-2,-1,0,1,2,2}, dyn = {1,1,-1,-1,0,1,2,2,2,2,2,1,0,-1,-2,-2,-2,-2,-2,-1};
void dfs_new(vector<pair<int,int>> &p) {
  rep(i,p.size()) {
    int x = p.at(i).first,y = p.at(i).second;
      rep(j,dxn.size()) {
          int nx = x + dxn.at(j),ny = y + dyn.at(j);
          if(isin(nx,0,h) and isin(ny,0,w) and !seen.at(nx).at(ny) and maze.at(nx).at(ny)) {
            // new_place.at(nx).at(ny) = 1;
            path={};
            dfs_seen(nx,ny);
            que.push(path);
            loop++;
          }
      }
  }
}


int main() {

  cin >> h >> w;
  int ch,cw,dh,dw;cin >> ch >> cw >> dh >> dw;
  ch--;cw--;dh--;dw--;
  maze = vector<vector<int>>(h,vector<int>(w,0));
  seen = vector<vector<int>>(h,vector<int>(w,0));
  new_place = vector<vector<int>>(h,vector<int>(w,0));
  tmp_new_place = new_place;

  rep(i,h)  {
    string s; cin >> s;
    rep(j,w) {
    if(s.at(j)=='.')  maze.at(i).at(j) = 1;
    else maze.at(i).at(j) = 0;
    }
  }

  int ans = -1;
  int sx = ch,sy = cw;
  dfs_seen(sx,sy);
  int tmp = 0;
  if(seen.at(dh).at(dw)) {
    cout << 0 << endl;
    return 0;
  }

  que.push(path);
  dfs_new(que.front());que.pop();
  while(true) {
    int tloop = loop;
    if(loop==0) break;
    tmp++;
    loop = 0;
    rep(i,tloop) {
      if(seen.at(dh).at(dw)) {
        ans = tmp;
        break;
      }
      dfs_new(que.front());que.pop();
    }
  }

  cout << ans << endl;

  return 0;
}
