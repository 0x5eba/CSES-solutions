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

struct FenwickTree {
    vector<ll> bit; 
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    // FenwickTree(vector<ll> a) : FenwickTree(a.size()) {
    //     for (size_t i = 0; i < a.size(); i++)
    //         update(i, a[i]); // puo' essere update(i, i, a[i])
    // }

    ll query(int r) {
        ll ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    ll query(int l, int r) {
        return query(r) - query(l - 1);
    }

    void update(int idx, int val) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += val;
    }

    void update(int l, int r, int val) {
        update(l, val);
        update(r + 1, -val);
    }

    void print(){
        for(auto a : bit)
            cout << a << " ";
        cout << endl;
    }
};

vector<vector<int>> adj;
vector<int> nChilds;

void topologicalSortUtil(int v, vector<bool> &visited, stack<int> &Stack) { 
    visited[v] = true; 
    // Recur for all the vertices adjacent to this vertex 
    for(auto i : adj[v])
        if (!visited[i])
            topologicalSortUtil(i, visited, Stack); 
    // Push current vertex to stack which stores result 
    Stack.push(v); 
} 

vector<int> topologicalSort(int V){ 
    stack<int> Stack; 
    vector<bool> visited(V, false);
    
    // Call the recursive helper function to store Topological 
    // Sort starting from all vertices one by one 
    for (int i = 1; i < V; i++) 
        if (!visited[i]) 
            topologicalSortUtil(i, visited, Stack); 
    vector<int> v;
    while(!Stack.empty()){ 
        v.emplace_back(Stack.top());
        Stack.pop(); 
    } 
    return v;
} 

vector<int> ids;
void dfs(int node, vector<bool> &visited){
    visited[node] = true; 
    ids.emplace_back(node);
    for(auto a : adj[node]){
        if(!visited[a])
            dfs(a, visited);
    }
}

void count_subnode(int s, int e) {
    nChilds[s] = 1;
    for(auto child : adj[s]){
        if(child == e) 
            continue;
        count_subnode(child, s);
        nChilds[s] += nChilds[child];
    }
}


int main() { 
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N = getint<int>();
    int Q = getint<int>();
    adj.resize(N+2);
    nChilds.resize(N+2);
    vector<int> v(N+2);

    for(int a = 1; a <= N; ++a){
        int val = getint<int>();
        v[a] = val;
    } 

    for(int a = 0; a < N-1; ++a){
        int parent = getint<int>();
        int child = getint<int>();
        adj[parent].emplace_back(child);
        adj[child].emplace_back(parent);
    } 

    auto ids = topologicalSort(N+1);
    vector<int> rev_ids(N+1);
    for(int a = 0; a < N; ++a){
        rev_ids[ids[a]] = a+1;
    }

    count_subnode(1, 0);

    auto BIT = FenwickTree(N+2);
    for(int a = 1; a <= N; ++a){
        BIT.update(a, v[ids[a-1]]);
    }

    for(int a = 0; a < Q; ++a){
        int type = getint<int>();
        if(type == 1){ // change the value of node s to x
            int s = getint<int>();
            int x = getint<int>();

            auto diff = v[s] - x;
            v[s] = x;

            s = rev_ids[s];

            BIT.update(s, -diff);

        } else { // sum of values cin the subtree of node s
            int s = getint<int>();
            
            auto size = nChilds[s]-1;

            s = rev_ids[s];

            cout << BIT.query(s, s+size) << "\n";
        }
    } 

}