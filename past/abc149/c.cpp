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

// int n以下の素数リスト
struct PrimeTable {
  int n;
  vector<int> sieve, primes;
  PrimeTable(int n) : n(n), sieve(n+1) {
    sieve[0] = sieve[1] = -1;
    for(long long i = 2;i < n+1;++i) {
      if (sieve[i]) continue;
      primes.emplace_back(i);
      sieve[i] = i;
      // 一番小さい素因数のみ記録する
      for (long long j = i*i; j <= n; j += i) if (!sieve[j]) sieve[j] = i;
    }
  }
  bool isPrime(int m) { return sieve[m] == m; }
  vector<int> factorList(int x) {
    vector<int> res;
    if(x == 0) {
      res.emplace_back(0);
      return res;
    } else if(x == 1) {
      res.emplace_back(1);
      return res;
    }
    while (x != 1) {
      res.emplace_back(sieve[x]);
      x /= sieve[x];
    }
    return res;
  }
  vector<pair<int,int>> factorPair(int x) {
    vector<int> fl = factorList(x);
    vector<pair<int,int>> res(1, pair<int,int>(fl[0], 0));
    for (int p : fl) {
      if (res.back().first == p) res.back().second++;
      else res.emplace_back(p, 1);
    }
    return res;
  }
};

int main() {
  int x;
  cin >> x;
  PrimeTable prime=PrimeTable(1e6);

  srep(i,x,x+10000) {
    if(prime.isPrime(i)) {
      cout << i << endl;
      break;
    }
  }


  return 0;
}
