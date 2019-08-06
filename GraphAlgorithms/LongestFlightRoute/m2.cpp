#include <cstdio>
#include <vector>
#include <algorithm>
 
const int INF=1e9+7;
 
int dp[200005];
std::vector<int> to[200005];
bool vis[200005];
 
int N;
 
void dfs(int node){
  if(vis[node]) return;
  vis[node]=true;
  dp[node]=(node!=N-1)?-INF:0;
  for(int child:to[node]){
    dfs(child);
    dp[node]=std::max(dp[node],dp[child]+1);
  }
}
 
int main(){
  int M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<M;i++){
    int A,B;
    scanf("%d %d",&A,&B);
    A--,B--;
    to[A].push_back(B);
  }
  dfs(0);
  if(dp[0]<0){
    printf("IMPOSSIBLE\n");
  }else{
    printf("%d\n",dp[0]+1);
    int x=0;
    while(x!=N-1){
      printf("%d ",x+1);
      for(int y:to[x]){
	if(dp[y]==dp[x]-1){
	  x=y;
	  break;
	}
      }
    }
    printf("%d\n",N);
  }
  return 0;
}