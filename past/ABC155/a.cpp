#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n) ; ++i)
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

template<typename T>
void printVec(vector<T> vec) {
  cout << "[";
  for(auto& v : vec) {
    cout << v << ",";
  }
  cout << "]" << endl;
}

int main() {
  int a,b,c;
  cin >> a >> b >> c;
  int n = 0;
  if(a==b) n++;
  if(b==c) n++;
  if(a==c) n++;

  if(n==1) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }


  return 0;
}
