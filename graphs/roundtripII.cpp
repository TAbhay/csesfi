#include "bits/stdc++.h"
using namespace std;
#define int long long
#define uint unsigned long long int	
#define debug(x) cout<<" "<<x<" ";
#define InfinityIsHere ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const  int mod = 1e9+7;
int N=1e15+10;
int test =1;
int cys ,cye;
vector<int> adj[200005];
vector<int> visited(100005,0);
int parent[100005];
bool dfs(int v){
    visited[v] = 1;
    for(auto u : adj[v]){
        if(visited[u]==0){
            parent[u]  = v;
            if(dfs(u)){
               
               return true;
            }
        }
        else if(visited[u]==1){
            cys = u;
            cye = v;
            return true;
        }
    }
    visited[v] = 2;
    return false;
}
void solve(){
  int n,m;
  cin >> n >> m;
   int u,v;
   for(int i=0;i<m;i++){
       cin>>u>>v;
       adj[u].push_back(v);
       //adj[v].push_back(u);
   }
   for(int i=1;i<=n;i++){
       if(visited[i]==0){
           if(dfs(i)){
              vector<int> ans;
              ans.push_back(cys);
              for (int v = cye; v != cys; v = parent[v])
             ans.push_back(v);
             ans.push_back(cys);
             reverse(ans.begin(),ans.end());
             cout<<ans.size()<<endl;
            for (int v : ans)
            cout << v << " ";
               cout << endl;
               return;
               }
           
       }
   }
   cout<<"IMPOSSIBLE";
}
             
signed main(){
    InfinityIsHere;
    int  t =1;
  
    while(t--){
        solve();
      
    }
}