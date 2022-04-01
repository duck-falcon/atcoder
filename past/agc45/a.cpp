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

vvi a(204,vi(67,0));
vvi one(204,vi(67,0));
vvi zero(204,vi(67,0));

void shokika(int n,int mx) {
  rep(i,n+1) rep(j,mx+2) {
    a.at(i).at(j) = 0;
    one.at(i).at(j) = 0;
    zero.at(i).at(j) = 0;
  }
}

vi vecadd(vi veca,vi vecb,int mx) {
  vi ans(mx+2,0);
  rep(i,mx+2) {
    ans.at(i) = veca.at(i) ^ vecb.at(i);
  }
  return ans;
}

void hakidasi(int n, int mx,int z,int o) {
  int ue=-1;
  rep(j,mx+1) {
    bool flag=true;
    vi tmp;
    int koko=-1;
    srep(i,ue+1,n+1){
      if(zero.at(i).at(j) == 1 and flag) {
        flag=false;
        koko=i;
        ue+=1;
        continue;
      }
    }
    if(!flag) {
      rep(i,n+1) {
        if(i==koko) continue;
        if(zero.at(i).at(j)==1) {
          zero.at(i)=vecadd(zero.at(i),zero.at(koko),mx);
        }
      }
    }
    if(koko!=-1) swap(zero.at(koko),zero.at(ue));
  }

  ue=-1;
  rep(j,mx+1) {
    bool flag=true;
    vi tmp;
    int koko=-1;
    srep(i,ue+1,n+1){
      if(one.at(i).at(j) == 1 and flag) {
        flag=false;
        koko=i;
        ue+=1;
        continue;
      }
    }
    if(!flag) {
      rep(i,n+1) {
        if(i==koko) continue;
        if(one.at(i).at(j)==1) {
          one.at(i)=vecadd(one.at(i),one.at(koko),mx);
        }
      }
    }
    if(koko!=-1) swap(one.at(koko),one.at(ue));
  }
}

bool checkzero(vi veca) {
  rep(i,veca.size()) {
    if(veca.at(i)) return false;
  }
  return true;
}

bool kousei(int n,int mx,int z,int o) {
  int v=0;
  int zrank=0;
  while(!checkzero(zero.at(v))) {
    zrank++;
    v++;
  }
  rep(i,n+1) {
    vvi zero2=zero;
    zero2.at(z) = (one.at(i));
    int ue=-1;
    rep(j,mx+1) {
      bool flag=true;
      vi tmp;
      int koko=-1;
      srep(i,ue+1,z+2){
        if(zero2.at(i).at(j) == 1 and flag) {
          flag=false;
          koko=i;
          ue+=1;
          continue;
        }
      }
      if(!flag) {
        rep(i,z+1) {
          if(i==koko) continue;
          if(zero2.at(i).at(j)==1) {
            zero2.at(i)=vecadd(zero2.at(i),zero2.at(koko),mx);
          }
        }
      }
      if(koko!=-1) swap(zero2.at(koko),zero2.at(ue));
    }
    int vv=0;
    int zrank2=0;
    while(!checkzero(zero2.at(vv))) {
      zrank2++;
      vv++;
    }
    if(zrank2>zrank) return false;
  }
  return true;
}

int main() {
  int t;
  cin >> t;
  rep(kkkk,t) {
    int n;
    cin >> n;
    ll mx=0;
    rep(i,n) {
      ll tmp;
      cin >> tmp;
      rep(j,65) if(tmp>>j&1) {
        a.at(i).at(j)=1;
        mx = max(j,mx);
      }
      mx++;
    }
    string s;
    cin >> s;
    int z=0,o=0;
    rep(i,n) {
      if(s.at(i)=='0') {
        zero.at(z) = a.at(i);
        z++;
      } else {
        one.at(o) = a.at(i);
        o++;
      }
    }
    hakidasi(n,mx,z,o);
    if(kousei(n,mx,z,o)) cout << 0 << endl;
    else cout << 1 << endl;
    shokika(n,mx);
  }

  return 0;
}
