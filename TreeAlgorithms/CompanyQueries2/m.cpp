#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#define PARR(arr) for(auto a : arr) cout << a << " ";

template<typename T> T getint() {
	T val=0;
	char c;
	bool neg=false;
	while((c=getchar()) && !(c>='0' && c<='9')) {
		neg|=c=='-';
	}
	do {
		val=(val*10)+c-'0';
	} while((c=getchar()) && (c>='0' && c<='9'));
 
	return val*(neg?-1:1);
}

vector<vector<int>> adj;
vector<int> ids;
void dfs(int node, vector<bool> &visited){
    visited[node] = true; 
    ids.emplace_back(node);
    for(auto a : adj[node]){
        if(!visited[a])
            dfs(a, visited);
        if(adj[node].size())
            ids.emplace_back(node);
    }
}

vector<int> bfs(int node, int N) { 
    bitset<300000> visited;
    vector<int> depths(N+2);

    queue<int> q; 
    q.push(node); 
    int depth = 2;
    depths[1] = 1;

    visited.set(node); 
    while (!q.empty()) { 
        auto u = q.front(); 
        q.pop(); 

        auto depth_parent = depths[u];
        
        for(auto child : adj[u]){
            if (!visited.test(child)) { 
                visited.set(child);
                q.push(child);
                depths[child] = depth_parent+1;
            } 
        } 
    } 

    return depths;
} 

#define sz 400100
int FAI[sz];     // stores first appearence index of every node 
int level[sz];   // stores depth for all nodes in the tree 
int ptr;         // pointer to euler walk 
int dp[sz][18];  // sparse table 
int logn[sz];    // stores log values 
int p2[20];      // stores power of 2 
  
void buildSparseTable(vector<int> &depthArr) { 
    int n = depthArr.size();
    // initializing sparse table 
    memset(dp,-1,sizeof(dp)); 
  
    // filling base case values 
    for (int i=1; i<n; i++) 
        dp[i-1][0] = (depthArr[i]>depthArr[i-1])?i-1:i; 
  
    // dp to fill sparse table 
    for (int l=1; l<15; l++) 
      for (int i=0; i<n; i++) 
        if (dp[i][l-1]!=-1 and dp[i+p2[l-1]][l-1]!=-1) 
          dp[i][l] = 
            (depthArr[dp[i][l-1]]>depthArr[dp[i+p2[l-1]][l-1]])? 
             dp[i+p2[l-1]][l-1] : dp[i][l-1]; 
        else
             break; 
} 
  
int query(vector<int> &depthArr, int l,int r) 
{ 
    int d = r-l; 
    int dx = logn[d]; 
    if (l==r) return l; 
    if (depthArr[dp[l][dx]] > depthArr[dp[r-p2[dx]][dx]]) 
        return dp[r-p2[dx]][dx]; 
    else
        return dp[l][dx]; 
} 
  
void preprocess() { 
    // memorizing powers of 2 
    p2[0] = 1; 
    for (int i=1; i<18; i++) 
        p2[i] = p2[i-1]*2; 
  
    // memorizing all log(n) values 
    int val = 1,ptr=0; 
    for (int i=1; i<sz; i++) 
    { 
        logn[i] = ptr-1; 
        if (val==i) 
        { 
            val*=2; 
            logn[i] = ptr; 
            ptr++; 
        } 
    } 
} 

int LCA(int u,int v) { 
    // trival case 
    if (u==v) 
       return u; 
  
    if (FAI[u] > FAI[v]) 
       swap(u,v); 
  
    // doing RMQ in the required range 
    return ids[query(FAI[u], FAI[v])]; 
} 


int main() { 
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // ifstream input("test_input.txt");
    // int N, Q; input >> N >> Q;

    int N = getint<int>();
    int Q = getint<int>();
    adj.resize(N+2);
    
    for(int a = 0; a < N-1; ++a){
        int boss = getint<int>();
        // int boss; input >> boss;
        int employee = a+2;
        // adj[employee] = boss;
        adj[boss].emplace_back(employee);
    } 
    
    vector<bool> visited(N+1);
    dfs(1, visited);
    auto depths = bfs(1, N);
    // PARR(ids);
    // cout << endl;
    // PARR(depths);
    // cout << endl;

    vector<int> all_depths;
    for(auto a : ids){
        all_depths.emplace_back(depths[a]);
    }

    preprocess(); 
    buildSparseTable(all_depths);

    for(int a = 0; a < Q; ++a){
        int e1 = getint<int>();
        int e2 = getint<int>();

        cout << query(all_depths, e1, e2) << "\n";
    }

}