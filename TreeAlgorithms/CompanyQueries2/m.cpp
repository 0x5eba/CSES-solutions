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
 
    vector<int> all_depths;
    for(auto a : ids){
        all_depths.emplace_back(depths[a]);
    }

    for(int a = 0; a < Q; ++a){
        int e1 = getint<int>();
        int e2 = getint<int>();

        // cout << query(all_depths, e1, e2) << "\n";
    }

}