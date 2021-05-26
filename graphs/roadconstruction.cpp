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
int mxcnt = 0;
int np = 0;
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
        np--;
        size[a]+=size[b];
        mxcnt = max(mxcnt,size[a]);
    }
}
void solve(){
  int n,m;
  cin>>n>>m;
  np = n;
  makeSet();
  for(int i=0;i<m;i++){
      int u,v;
      cin>>u>>v;
      makeUnion(u,v);
      cout<<np<<" "<<mxcnt<<"\n";
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