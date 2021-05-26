#include "bits/stdc++.h"
using namespace std;
#define int long long
#define uint unsigned long long int	
#define debug(x) cout<<" "<<x<" ";
#define InfinityIsHere ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const  int mod = 1e9+7;
int N=1e16+10;
int test =1;
vector<int> parent(100005,0);
vector<int> size(100005,0);
void makeSet(){
    for(int i=0;i<100005;i++){
        parent[i] = i;
        size[i] = 1;
    }
}
int get(int v){
    if(parent[v]==v){
        return v;
    }
    return parent[v] = get(parent[v]);
}
void makeUnion(int a,int b){
    a = get(a);
    b = get(b);
    if(a!=b){
        if(size[a]<size[b]){
            swap(a,b);
        }
        parent[b] = a;
        size[a]+=size[b];
    }
}
void solve(){
  int n,m;
  cin>>n>>m;
  vector<pair<int,pair<int,int> > > e;
  for(int i=0;i<m;i++){
      int u,v,w;
      cin>>u>>v>>w;
      e.push_back({w,{u,v}});
  }
  makeSet();
  int ans = 0;
  sort(e.begin(),e.end());
  int cnt =0;
  for(auto t : e){
      int w = t.first;
      int u = t.second.first;
      int v = t.second.second;
      if(get(u)!=get(v)){
          ans+=w;
          makeUnion(u,v);
          cnt++;
          
      }
  }
  if(cnt==n-1){ cout<<ans;   }
  else{ cout<<"IMPOSSIBLE";   }
}          //            7   8   9  
signed main(){
    InfinityIsHere;
    int  t =1;
    //cin>>t;
    while(t--){
        solve();
      
    }
}