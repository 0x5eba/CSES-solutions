#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvii vector<vector<pair<int, int>>>
#define vvl vector<vector<ll>>
#define vvll vector<vector<pair<ll, ll>>>
#define FOR(x, N) for(x = 0; x < N; ++x)
#define epsilon 1e-9
#define INF 3e18 + 5
#define MOD 1000000007
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
template<class... Args>
inline void print(Args&&... args){
    ((cout << args << " "), ...) << "\n";
}
template<class T>
inline void parr(vector<T> arr){
    for(auto a : arr) cout << a << " ";
    cout << "\n";
}

const int N = 200005;
const int logN = 20;

vector<int> adj[N];
int depth[N];
int p[N][logN];

int lca(int a, int b){
    if(depth[a] > depth[b]) 
        swap(a, b);
    
    int diff = depth[b] - depth[a];
    for(int i = 0; i < logN; i++)
        if(diff & (1 << i))
            b = p[b][i];
    
    if(a == b) 
        return a;
    
    for(int i = logN - 1; i >= 0; i--)
        if(p[b][i] != p[a][i])
            b = p[b][i], a = p[a][i];  
    
    return p[a][0];
}


void dfs(int v, int f, int d){
    depth[v] = d;
    int curr = p[v][0] = f;
 
    for(int i = 1; i < logN && (1 << i) <= d; i++){
        p[v][i] = p[curr][i - 1];
        curr = p[curr][i - 1];
    }
 
    for(auto u : adj[v])
        if(u != f)
            dfs(u, v, d+1);
}

ll dist(int u, int v) {
    return depth[u]+depth[v]-2*depth[lca(u,v)];
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q, a, b;
    n = getint<int>(); 
    q = getint<int>();

    for(int i = 1; i < n; i++){
        a = getint<int>();
        a--;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }
    dfs(0, -1, 0);

    while(q--){
        a = getint<int>(); 
        b = getint<int>();  
        cout << lca(a - 1, b - 1) + 1 << "\n";
    }
}