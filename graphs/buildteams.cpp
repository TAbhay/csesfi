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
 
void solve(){
  int n,m;
  cin >> n >> m;
   int u,v;
   for(int i=0;i<m;i++){
       cin>>u>>v;
       adj[u].push_back(v);
       adj[v].push_back(u);
   }
   for(int i=1;i<=n;i++){
       if(visited[i]==0){
           queue<pair<int,int > > q;
           visited[i] = 1;
           q.push({i,1});
           while(!q.empty()){
               auto t = q.front();
               int v = t.first;
               int col = t.second;
               q.pop();
               for(auto u : adj[v]){
                  if(visited[u]==col){
                      cout<< "IMPOSSIBLE";
                      return;
                  }
                  if(visited[u]==0){
                      visited[u] = col==2?1:2;
                      q.push({u,visited[u]});
                  }
               }
           }
       }
   }
   for(int i =1;i<=n;i++){
       cout<<visited[i]<<" ";
   }
}
              
signed main(){
    InfinityIsHere;
    int  t =1;
  
    while(t--){
        solve();
      
    }
}