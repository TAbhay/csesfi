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
vector<int > adj[200005];
vector<int> visited(100005,0);
//vector<int> d(100005,INT_MAX);
 
vector<int> ans;
void dfs(int v){
  visited[v] = true;
  for(auto u :  adj[v]){
    if(!visited[u]){
        dfs(u);
    }
  }
}
void solve(){
  int n,m;
  cin >> n >> m;
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  queue<int> q;
  q.push(1);
  vector<int> p(n+1,-1);
  vector<int> d(n+1,1);
  while(!q.empty()){
      int v = q.front();
      q.pop();
      visited[v] = true;
      for(auto u : adj[v]){
          if(!visited[u]){
              visited[u] = true;
              q.push(u);
              d[u] = d[v] +1;
              p[u] = v;
          }
      }
  }
  if(!visited[n]){
      cout<<"IMPOSSIBLE\n";
      return;
  }
  cout<<d[n]<<"\n";
  vector<int> ans;
  for(int v = n ; v!=-1; v =p[v]){
      ans.push_back(v);
  }
  reverse(ans.begin(),ans.end());
  for(auto t : ans){
      cout<<t<<" ";
  }
 
}
              
signed main(){
    InfinityIsHere;
    int  t =1;
  
    while(t--){
        solve();
      
    }
}