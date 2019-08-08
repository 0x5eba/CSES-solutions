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
  
int bfs(int start, int end) { 
    bitset<300000> visited;
    int depth = 0;

    queue<int> q; 
    q.push(start); 

    visited.set(start); 
    while (!q.empty()) { 
        auto u = q.front(); 
        q.pop(); 

        if(u == end){
            if(depth == 0)
                return 0;
            return depth-1;
        }

        for(auto child : adj[u]){
            if (!visited.test(child)) { 
                visited.set(child);
                q.push(child);
            } 
        } 

        depth++;
    } 
} 


int main() { 
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N = getint<int>();
    int Q = getint<int>();
    adj.resize(N+3);
    
    for(int a = 0; a < N-1; ++a){
        int parent = getint<int>();
        int child = getint<int>();
        adj[parent].emplace_back(child);
        adj[child].emplace_back(parent);
    } 

    for(int a = 0; a < Q; ++a){
        int start = getint<int>();
        int end = getint<int>();
        cout << bfs(start, end) << "\n";
    }
}