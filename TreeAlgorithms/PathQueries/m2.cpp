#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#define MOD 1000000007
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

#define MAXN 6000010
#define INF 3e18 + 5
typedef long long ll;
// #define numeric_limits<ll>::max()-1;
ll tree[MAXN];
ll lazy[MAXN];

int N;
void propaga(int inx, int cnt_num){
    if (lazy[inx]){
        tree[inx] += lazy[inx]*cnt_num;
        lazy[inx*2] += lazy[inx];
        lazy[inx*2+1] += lazy[inx];
        lazy[inx] = 0;
    }
}

void update(int tl, int tr, ll val,int l = 0, int r = N+1, int inx = 1){
    propaga(inx,r-l);
    // tutto fuori
    if (tr <= l || tl >= r || r <= l)
        return;
    // att dentro target
    int cnt_num = r-l;

    if (tl <= l && tr >= r){
        lazy[inx] += val;
        propaga(inx,cnt_num);
        return;
    }
    propaga(inx, cnt_num);
    int mid = (l+r)/2;
    update(tl,tr,val,l,mid,inx*2);
    update(tl,tr,val,mid,r,inx*2+1);
    tree[inx] = tree[inx*2] + tree[inx*2+1];
}

ll query(int tl, int tr, int l = 0, int r = N+1, int inx = 1){
    propaga(inx, r-l);

    // tutto fuori
    if (tr <= l || tl >= r)
        return 0;

    // att dentro target
    if (tl <= l && tr >= r)
        return tree[inx];

    int mid = (l+r)/2;
    return query(tl,tr,l,mid,inx*2) + query(tl,tr,mid,r,inx*2+1);
}

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

    N = getint<int>();
    int Q = getint<int>();
    adj.resize(N+2);
    nChilds.resize(N+2);
    vector<ll> v(N+2);

    for(int a = 1; a <= N; ++a){
        v[a] = getint<int>();
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

    vector<ll> sums(N+2);
    for(int a = 1; a <= N; ++a){

        auto parents = adj[ids[a-1]];
        ll sum = v[ids[a-1]];
        for(auto parent : parents){
            if(sums[parent] == 0)
                continue;

            sum += sums[parent];
            break;
        }

        // cout << "parent of " << ids[a-1] << " " << parent;
        // cout << "\nAdd " << sums[parent] << " " << v[ids[a-1]] << endl;
        // auto sum = sums[parent] + v[ids[a-1]];
        update(a, a+1, sum);
        sums[ids[a-1]] = sum;
    }

    for(int a = 0; a < Q; ++a){
        int type = getint<int>();
        if(type == 1){ // change the value of node s to x
            int s = getint<int>();
            int x = getint<int>();

            auto diff = v[s] - x;
            v[s] = x;
            
            auto size = nChilds[s]-1;
            s = rev_ids[s];
            update(s, s+size+1, -diff);

        } else { // sum of values cin the subtree of node s
            int s = getint<int>();

            s = rev_ids[s];
            cout << query(s, s+1) << "\n";
        }
    } 

}