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

vector<ll> a;

void newlun(ll v){
  if(v % 10 == 1) {
    a.emb(v*10);
    a.emb(v*10+1);
    a.emb(v*10+2);
  } else if(v % 10 == 2) {
    a.emb(v*10+1);
    a.emb(v*10+2);
    a.emb(v*10+3);
  } else if(v % 10 == 3) {
    a.emb(v*10+2);
    a.emb(v*10+3);
    a.emb(v*10+4);
  } else if(v % 10 == 4) {
    a.emb(v*10+3);
    a.emb(v*10+4);
    a.emb(v*10+5);
  } else if(v % 10 == 5) {
    a.emb(v*10+4);
    a.emb(v*10+5);
    a.emb(v*10+6);
  } else if(v % 10 == 6) {
    a.emb(v*10+5);
    a.emb(v*10+6);
    a.emb(v*10+7);
  } else if(v % 10 == 7) {
    a.emb(v*10+6);
    a.emb(v*10+7);
    a.emb(v*10+8);
  } else if(v % 10 == 8) {
    a.emb(v*10+7);
    a.emb(v*10+8);
    a.emb(v*10+9);
  } else if(v % 10 == 9) {
    a.emb(v*10+8);
    a.emb(v*10+9);
  } else if(v % 10 == 0) {
    a.emb(v*10);
    a.emb(v*10+1);
  }
}

int main() {
  int k;
  cin >> k;
  for(int i = 1;i<=9;i++) {
    a.emb(i);
    if(i==k) {
      cout << k << endl;
      return 0;
    }
  }

  int num = 9;
  while(1) {
    vector<ll> old;
    swap(a,old);
    for(auto v : old) {
      newlun(v);
    }
    if(num + a.size() >= k) break;
    num += a.size();
  }

  cout << a.at(k - num - 1) << endl;


  return 0;
}
