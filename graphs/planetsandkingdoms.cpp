#include "bits/stdc++.h"
using namespace std;
//#define int long long
 
#define InfinityIsHere ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const int mod = 1e9+7;
int N=1e7+7;
int test =1;
vector<int> adj[100005];
vector<int> adjT[100005];
vector<int> component;
int kingdom[100005];
vector<int> order;
int visited[100005];
int cnt =0;
void dfs1(int v){
    visited[v]  = 1;
    for(auto u : adj[v]){
        if(!visited[u]){
            dfs1(u);
        }
    }
    order.push_back(v);
}
void dfs2(int v){
  visited[v] = true;
  component.push_back(v);
  for(auto u : adjT[v]){
      if(!visited[u]){
          dfs2(u);
      }
  }  
}
void solve(){
   int n,m;
   cin>>n>>m;
   for(int i=0;i<m;i++){
       int a,b;
       cin>>a>>b;
       adj[a].push_back(b);
       adjT[b].push_back(a);
      
   }
  // component.resize(5);
   memset(visited,0,sizeof(visited));
   memset(kingdom,0,sizeof(kingdom));
   for(int i=1;i<=n;i++){
       if(!visited[i]){
           dfs1(i);
       }
   }
   memset(visited,0,sizeof(visited));
   reverse(order.begin(),order.end());
   for(auto u: order){
       if(!visited[u]){
        dfs2(u);
        cnt++;
        for(auto planet : component){
            kingdom[planet] = cnt;
        }
       }
       component.clear();
   }
   cout<<cnt<<" \n";
   for(int i=1;i<=n;i++){
       cout<<kingdom[i]<<" ";
   }
};                
int main(){
    InfinityIsHere;
    int  t =1;
    
 //  cin>>t;
    
    while(t--){
        solve();
      
    }
}