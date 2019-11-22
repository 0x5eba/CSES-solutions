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


#define sz 400100
vector<ll> adj[sz];    // stores the tree 
vector<ll> euler;      // tracks the eulerwalk 
vector<ll> depthArr; 
ll FAI[sz];     // stores first appearence index of every node 
ll level[sz];   // stores depth for all nodes in the tree 
ll ptr = 0;         // pointer to euler walk 
ll dp[sz][30];  // sparse table 
ll logn[sz];    // stores log values 
ll p2[30];      // stores power of 2 
  
void buildSparseTable(){
    // creating depthArray corresponding to euler[]
    for (auto x : euler) 
        depthArr.push_back(level[x]);
    int n = depthArr.size(); 

    memset(dp,-1,sizeof(dp)); 
  
    for (int i=1; i<n; i++) 
        dp[i-1][0] = (depthArr[i] > depthArr[i-1]) ? i-1 : i; 
  
    for (int l=1; l<30; l++) 
        for (int i=0; i<n; i++) 
            if (dp[i][l-1] != -1 and dp[i+p2[l-1]][l-1] != -1) 
                dp[i][l] = (depthArr[dp[i][l-1]] > depthArr[dp[i+p2[l-1]][l-1]]) ? dp[i+p2[l-1]][l-1] : dp[i][l-1]; 
            else
                break; 
} 
  
int query(int l, int r) { 
    int d = r-l; 
    int dx = logn[d]; 

    if (l==r) 
        return l; 

    if (depthArr[dp[l][dx]] > depthArr[dp[r-p2[dx]][dx]]) 
        return dp[r-p2[dx]][dx]; 
    else
        return dp[l][dx]; 
} 
  
void preprocess(){ 
    // memorizing powers of 2 
    p2[0] = 1; 
    for (int i=1; i<30; i++) 
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
  
/** 
 * Euler Walk ( preorder traversal) 
 * converting tree to linear depthArray 
 * Time Complexity : O(n) 
 * */
void dfs(int cur,int prev,int dep) { 
    // marking FAI for cur node 
    if (FAI[cur]==-1) 
        FAI[cur] = ptr; 
  
    level[cur] = dep; 
  
    // pushing root to euler walk 
    euler.push_back(cur); 
  
    // incrementing euler walk pointer 
    ptr++; 
  
    for (auto x : adj[cur]) { 
        if (x != prev) 
        { 
            dfs(x,cur,dep+1); 
  
            // pushing cur again in backtrack 
            // of euler walk 
            euler.push_back(cur); 
  
            // increment euler walk pointer 
            ptr++; 
        } 
    } 
} 

  
ll LCA(int u,int v){ 
    // trival case 
    if (u==v) 
       return u; 
  
    if (FAI[u] > FAI[v]) 
       swap(u,v); 
  
    // doing RMQ in the required range 
    return euler[query(FAI[u], FAI[v])]; 
}

int main() { 
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // ifstream input("test_input.txt");
    // int N, Q; input >> N >> Q;

    int N = getint<int>();
    int Q = getint<int>();
    
    for(int a = 0; a < N-1; ++a){
        int boss = getint<int>();
        // int boss; input >> boss;
        int employee = a+2;
        // adj[employee] = boss;
        adj[boss].emplace_back(employee);
        adj[employee].emplace_back(boss);
    } 
    
    preprocess(); 
    memset(FAI,-1,sizeof(FAI)); 
    dfs(1,0,0);
    // building sparse table 
    buildSparseTable();

    for(int a = 0; a < Q; ++a){
        int e1 = getint<int>();
        int e2 = getint<int>();

        cout << LCA(e1, e2) << "\n";
    }
}