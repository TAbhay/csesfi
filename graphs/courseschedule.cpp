#include "bits/stdc++.h"
using namespace std;
#define int long long
#define uint unsigned long long int	
#define debug(x) cout<<" "<<x<" ";
#define InfinityIsHere ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const  int mod = 1e9+7;
int N=1e16+10;
int test =1;
vector<int> adj[200005];
vector<int> visited(100005,0);
vector<int> st;
bool dfs(int v){
    visited[v] = 1;
    for(auto u: adj[v]){
        if(visited[u]==0){
            if(dfs(u)){
                return true;
            }
        }
        else if(visited[u]==1){
            return true;
        }
    }
    visited[v] = 2;
    st.push_back(v);
    return false;
}
void solve(){
  int n,m;
  cin>>n>>m;
  for(int i=0;i<m;i++){
      int u,v;
      cin>>u>>v;
      adj[u].push_back(v);
  }
  int cnt = 0;
  for(int i=1;i<=n;i++){
      if(visited[i]==0){
          cnt++;
          if(dfs(i)){
              cout<<"IMPOSSIBLE\n";
              return;
          }
      }
  }
 
reverse(st.begin(),st.end());
for(auto t :st){
    cout<<t<<" ";
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