#include <bits/stdc++.h>
using namespace std;

int dp[105][4][2];

int main() {
string n;
cin >> n;
int l=n.size();
int K;
cin >> K;
dp[0][0][0]=1;
for (int i=0;i<l;i++){
for (int j=0;j<4;j++){
for (int k=0;k<2;k++){
int nd=n[i]-'0';
for (int d=0;d<10;d++){
int ni=i+1,nj=j,nk=k;
if (d!=0)nj++;
if (nj>K)continue;
if (k==0){
if (d<nd)nk=1;
if (d>nd)continue;
}
dp[ni][nj][nk]+=dp[i][j][k];
}
}}}
int ans = dp[l][K][0]+dp[l][K][1];
cout << ans <<endl;
}
