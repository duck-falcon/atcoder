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


int main() {
  int a,b;
  cin >> a >> b;
  if(a==1 and b ==1) cout << "Draw" << endl;
  else if(b==1) cout << "Bob" << endl;
  else if (a==1) cout << "Alice" << endl;
  else if(a<b) cout << "Bob" << endl;
  else if (b<a) cout << "Alice" << endl;
  else cout << "Draw" << endl;

  return 0;
}
