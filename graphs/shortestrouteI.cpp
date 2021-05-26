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
vector<pair<int,int> > adj[200005];
vector<int> visited(100005,0);
vector<int> d(100005,N);
void dijkstra(int s){
  d[s] = 0;
  priority_queue< pair<int,int> , vector<pair<int,int> > , greater<pair<int,int>> >  q;
  q.push({0,s});
  while(!q.empty()){
    auto it  = q.top();
    int dis  = it.first;
    int v = it.second;
    q.pop();
    if(dis!=d[v]){
        continue;
    }
    for(auto u : adj[v]){
        int to = u.first;
        int len = u.second;
       
        if( d[v] + len < d[to]){
          d[to] = d[v] + len;
          q.push({d[to],to});
         
        }
    }
  }
}
void solve(){
  int n,m;
  cin >> n >> m;
  for(int i=0;i<m;i++){
    int a,b,w;
    cin >> a >> b >> w;
    adj[a].push_back({b,w});
  }
   dijkstra(1);
   for(int i=1;i<=n;i++){
     cout<<d[i]<<" ";
   }
}
              
signed main(){
    InfinityIsHere;
    int  t =1;
  
    while(t--){
        solve();
      
    }
}