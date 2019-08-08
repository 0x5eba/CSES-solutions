#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

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
int N;
  
int bfs(int node, bool second) { 
    bitset<300000> visited;
    vector<int> diameter(N+2);

    queue<int> q; 
    q.push(node); 

    int max_elm = 0;
    int max_idx = 0;
  
    visited.set(node); 
    while (!q.empty()) { 
        auto u = q.front(); 
        q.pop(); 

        for(auto child : adj[u]){
            if (!visited.test(child)) { 
                visited.set(child);
                q.push(child);
  
                diameter[child] += diameter[u] + 1; 
                if(diameter[child] > max_elm){
                    max_elm = diameter[child];
                    max_idx = child;
                }
            } 
        } 
    } 

    if(second)
        return max_elm;
    return max_idx;
} 

int main() { 
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    N = getint<int>();
    adj.resize(N+3);
    
    for(int a = 0; a < N-1; ++a){
        int parent = getint<int>();
        int child = getint<int>();
        adj[parent].emplace_back(child);
        adj[child].emplace_back(parent);
    } 

    /* First, we choose an arbitrary node a in the tree and find the
    farthest node b from a. Then, we find the farthest node c from b. The diameter
    of the tree is the distance between b and c.
    */
    int lastNode = bfs(1, false); 
    cout << bfs(lastNode, true);
}