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

class heap {
  //  vi a;
    int end;

    void up(int n) {
      if(n==0) return;
      if(a.at((n-1)/2) < a.at(n)) {
        swap(a.at((n-1)/2),a.at(n));
        up((n-1)/2);
      }
      return;
    }

    void down(int n) {
      int i;
      if(2*n+1 >= end) return;
      else if(end == 2*n+2) i = 2*n+1;
      else i = a.at(2*n+1) < a.at(2*n+2) ? 2*n+2 :2*n+1;
      if(a.at(n) < a.at(i)) {
        swap(a.at(n),a.at(i));
        down(i);
      }
      return;
    }

  public:
    vi a;
    heap(int root) {
      end = 1;
      a.push_back(root);
    }

    int top() {
      return a.at(0);
    }

    void push(int b) {
      // 右下に追加
      if(a.size() > end) {
        a.at(end) = b;
      } else {
        a.eb(b);
      }

      // heap を保つ処理
      up(end);
      end++;
    }

    void pop() {
      end--;
      swap(a.at(0),a.at(end));
      down(0);
    }
};

class rheap {
  //  vi a;
    int end;

    void up(int n) {
      if(n==0) return;
      if(a.at((n-1)/2) > a.at(n)) {
        swap(a.at((n-1)/2),a.at(n));
        up((n-1)/2);
      }
      return;
    }

    void down(int n) {
      int i;
      if(2*n+1 >= end) return;
      else if(end == 2*n+2) i = 2*n+1;
      else i = a.at(2*n+1) > a.at(2*n+2) ? 2*n+2 :2*n+1;
      if(a.at(n) > a.at(i)) {
        swap(a.at(n),a.at(i));
        down(i);
      }

      return;
    }

  public:
    vi a;
    rheap(int root) {
      end = 1;
      a.push_back(root);
    }

    int top() {
      return a.at(0);
    }

    void push(int b) {
      // 右下に追加
      if(a.size() > end) {
        a.at(end) = b;
      } else {
        a.eb(b);
      }

      // heap を保つ処理
      up(end);
      end++;
    }

    void pop() {
      end--;
      swap(a.at(0),a.at(end));
      down(0);
    }
};

int main() {
  int n;cin >> n;
  ll sum;
  int minx;

  // 一回目
  int t;cin >> t;
  cin >> minx >> sum;
  heap mae=heap(minx);rheap ushiro=rheap(minx);

  rep(i,n-1) {
    int q;cin >> q;
    if(q==1) {
      int a,b;cin >> a >> b;
      sum+=b;

      // 最小値更新
      int l = mae.top();int r = ushiro.top();
      if(!isin(a,l,r+1)) {
        sum += min(abs(l-a),abs(r-a));
      }

      // 中央値更新
      mae.push(a);ushiro.push(a);
      if(mae.top() > ushiro.top()) {
        int x = mae.top();
        int y = ushiro.top();
        mae.pop();ushiro.pop();
        mae.push(y);ushiro.push(x);
      }
      minx = mae.top();
    } else {
      cout << minx << " " << sum << endl;
    }
  }
}
