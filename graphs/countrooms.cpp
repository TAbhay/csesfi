#include "bits/stdc++.h"
using namespace std;
#define int long long
#define uint unsigned long long int	
#define debug(x) cout<<" "<<x<" ";
#define InfinityIsHere ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const  int mod = 1e9+7;
int N=1e15+10;
int test =1;
//vector<int> st;
char g[1005][1005];
void dfs(int i,int j,int n,int m){
    if(i<0 || j<0 ||i==n || j== m || g[i][j]=='#' || g[i][j]=='*'){
        return;
    }
    g[i][j] = '*';
    dfs(i-1,j,n,m);
    dfs(i+1,j,n,m);
    dfs(i,j+1,n,m);
    dfs(i,j-1,n,m);
    return;
}
 
 
 
void solve(){
  int n,m;
  cin >> n >> m;
  for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
          cin>>g[i][j];
      }
  }
  int cnt  = 0;
  for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
          if(g[i][j]=='.'){ 
              dfs(i,j,n,m);
              cnt++;
          }
      }
  }
  cout<<cnt;
}
              
signed main(){
    InfinityIsHere;
    int  t =1;
  
    while(t--){
        solve();
      
    }
}