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
vector<string> ans;
int n,a,b,c;

void aba() {
  ans.eb("A");
  b--;a++;
}

void abb() {
  ans.eb("B");
  a--;b++;
}

void bcb() {
  ans.eb("B");
  c--;b++;
}

void bcc() {
  ans.eb("C");
  c++;b--;
}

void aca() {
  ans.eb("A");
  c--;a++;
}

void acc() {
  ans.eb("C");
  c++;a--;
}
int main() {
  cin >> n >> a >> b >> c;
  int loop = 0;

  rep(i,n) {
    string s;
    loop+=1;
    if(loop==n+1) break;
    cin >> s;
    if(s=="AB") {
      if(a==0 and b==0) {
        cout << "No" << endl;
        return 0;
      } else {
        if(a==0) aba();
        else if(b==0) abb();
        else if(a==1 && b==1) {
          string t;
          loop+=1;
          if(loop==n+1) {
            abb();
            break;
          }
          cin >> t;
          if(t=="BC") {
            abb();
            bcc();
          }
          else if(t=="AC"){
            aba();
            acc();
          } else {
            aba();
            abb();
          }
        }
        else if(a==1) aba();
        else abb();
      }
    } else if(s=="BC") {
      if(b==0 and c==0) {
        cout << "No" << endl;
        return 0;
      } else {
        if(b==0) bcb();
        else if(c==0) bcc();
        else if(b==1 && c==1) {
          string t;
          loop+=1;
          if(loop==n+1) {
            bcc();
            break;
          }
          cin >> t;
          if(t=="AC") {
            bcc();
            aca();
          }
          else if(t=="AB"){
            bcb();
            aba();
          } else {
            bcb();
            bcc();
          }
        }
        else if(b==1) bcb();
        else bcc();
      }
    }
    else if (s=="AC") {
      if(c==0 and a==0) {
        cout << "No" << endl;
        return 0;
      } else {
        if(c==0) acc();
        else if(a==0) aca();
        else if(c==1 && a==1) {
          string t;
          loop+=1;
          if(loop==n+1) {
            aca();
            break;
          }
          cin >> t;
          if(t=="BC") {
            acc();
            bcb();
          }
          else if(t=="AB"){
            aca();
            abb();
          } else {
            aca();
            acc();
          }
        }
        else if(c==1) acc();
        else aca();
      }
    }
  }
  cout << "Yes" << endl;
  rep(i,n) cout << ans.at(i) << endl;

  return 0;
}
