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

vvi cal(13,vi());
vvi ucal;
vi md={0,31,28,31,30,31,30,31,31,30,31,30,31};
void calccal(){
  orep(i,12) {
    int n=md.at(i);
    orep(j,n) cal.at(i).eb(j);
  }
  ucal = cal;
  ucal.at(2).eb(29);
}

int y=0,m=0,d=0;
void calplus(){
  vvi mycal;
  if(!(y%400)) mycal=ucal;
  else if(!(y%100)) mycal=cal;
  else if(!(y%4)) mycal=ucal;
  else mycal=cal;

  if(mycal.at(m).size()>d) d++;
  else {
    d=1;
    m+=1;
    if(m==13) {
      m=1;
      y++;
    }
  }

}

string f(int n) {
  string ans="";
  if(n/10==0) {
    ans+=to_string(0);
    ans+=to_string(n);
  } else {
    ans+=to_string(n/10);
    ans+=to_string(n%10);
  }
  return ans;
}

int main() {
  string s;
  cin >> s;
  rep(i,4) {
    y += (s.at(i) - '0') * pow(10,3-i);
  }
  rep(i,2) {
    m += (s.at(i+5) - '0') * pow(10,1-i);
  }
  rep(i,2) {
    d += (s.at(i+8) - '0') * pow(10,1-i);
  }
  calccal();

  while(y%(m*d)!=0) {
    calplus();
  }

  cout << y << "/" << f(m) << "/" << f(d) << endl;

  return 0;
}
