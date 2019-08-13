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
vector<int> dp1;
vector<int> dp2;

// find the diameter of the tree using Dynamic Programming 
int dfs(int node, int parent) { 
    int firstmax = -1; 
    int secondmax = -1; 
  
    // Traverse for all children of node 
    for (auto i : adj[node]) { 
        if (i == parent) 
            continue; 
  
        dfs(i, node); 
  
        // Find first max 
        if (firstmax == -1) { 
            firstmax = dp1[i]; 
        } 
        else if (dp1[i] >= firstmax) // Secondmaximum 
        { 
            secondmax = firstmax; 
            firstmax = dp1[i]; 
        } 
        else if (dp1[i] > secondmax) // Find secondmaximum 
            secondmax = dp1[i]; 
    } 
  
    // Base case for every node 
    dp1[node] = 1; 
    if (firstmax != -1) // Add 
        dp1[node] += firstmax; 
  
    // Find dp[2] 
    if (secondmax != -1) 
        dp2[node] = 1 + firstmax + secondmax; 
  
    // Return maximum of both 
    return max(dp1[node], dp2[node]); 
} 



int main() { 
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N = getint<int>();
    adj.resize(N+3);
    dp1.resize(N+3);
    dp2.resize(N+3);
    
    for(int a = 0; a < N-1; ++a){
        int parent = getint<int>();
        int child = getint<int>();
        adj[parent].emplace_back(child);
        // adj[child].emplace_back(parent);
    } 

    dfs(1, 0);

    for(auto a : dp1){
        cout << a << " ";
    }
    cout << endl;

    for(auto a : dp2){
        cout << a << " ";
    }
    cout << endl;
}