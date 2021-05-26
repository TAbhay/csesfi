#include "bits/stdc++.h"
using namespace std;
#define int long long
#define uint unsigned long long int	
#define debug(x) cout<<" "<<x<" ";
#define InfinityIsHere ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const  int mod = 1e9+7;
int N=1e16+10;
int test =1;
const int mxN = 1e5+5;
int dp[505][505];
void solve(){
   int n,m,q;
   cin>>n>>m>>q;
   memset(dp,N,sizeof(dp));
   for(int i=0;i<=n;i++){
      dp[i][i] = 0;
   }
   for(int i=0 ;i<m;i++){
       int a,b,c;
       cin>>a>>b>>c;
       dp[a][b] =min(dp[a][b],c);
       dp[b][a] = min(dp[b][a],c);
   }
   for(int k=1;k<=n;k++){
       for(int i=1;i<=n;i++){
           for(int j=1;j<=n;j++){
               dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
           }
       }
   }
   for(int i = 0;i<q;i++){
       int a,b;
       cin>>a>>b;
       if(dp[a][b]>=N){
           cout<<"-1\n";
       }else{
           cout<<dp[a][b]<<"\n";
       }
   }
}
            
signed main(){
    InfinityIsHere;
    int  t =1;
    //cin>>t;
    while(t--){
        solve();
      
    }
}