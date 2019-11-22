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
inline void parr(T arr){
    for(auto a : arr) cout << a << " ";
    cout << "\n";
}

vvi adj;
vi colors;
int Q, N, M, a, b, c;

vector<set<int>> distinct_colors;
void dfs(int node, vector<bool> &visited){
    visited[node] = true; 
    distinct_colors[node].insert(colors[node]);
    for(auto a : adj[node]){
        if(!visited[a]){
            dfs(a, visited);
            distinct_colors[node].insert(colors[a]);
            for(auto b : distinct_colors[a]){
                distinct_colors[node].insert(b);
            }
        }
    }
}

int main() { 
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N = getint<int>(); 
    adj.resize(N+1);
    distinct_colors.resize(N+1);
    colors.resize(N+1);
    FOR(a, N){
        colors[a+1] = getint<int>(); 
    }
    FOR(c, N-1){
        a = getint<int>();
        b = getint<int>();
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> visited(N+1);
    dfs(1, visited);

    for(a = 1; a < N+1; ++a){
        cout << distinct_colors[a].size() << " ";
    }
}