#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

const long long MOD = 1000000007;

int main(){
  string x;
  ll m;
  cin >> x >> m;

  int s=x.size();
  int a=0;
  rep(i,s){
    a=max(a,x.at(i)-'0');
  }
  if(x.size()==1) {
    if(a<=m) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
  }

  ll r=1+1e18,l=0;
  while(r-l>0){

    ll mm=m;
    ll t=(r+l)/2,y=0;
    //cout << l << " " << r << " " << t <<endl;
    bool ck=true;
    rep(i,s){
      int k=1;
      ll z=x.at(i)-'0';
      while(k<s-i){
        ll tmp = z*t;
        if(tmp/z != t) {
          ck = false;
          break;
        }
        z*=t;
        //cout << z << endl;
        if(z>mm){
          ck=false;
          break;
        }
        k++;
      }
      if(ck){
        y+=z;
        if(y<0) {
          ck = false;
        }
        mm-=z;
        if(mm<0) ck=false;
      }
      else break;
    }

    if(ck) l=t;
    else r=t;
  }
  cout << l-a << endl;
}
