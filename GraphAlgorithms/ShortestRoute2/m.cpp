#include<bits/stdc++.h>
using namespace std;
 
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
 
#define INF 3e18
 
void floydWarshall(vector<vector<long long>> &adj, int N)  {  
    for (int k = 0; k < N; k++){  // Pick all vertices as source one by one 
        for (int i = 0; i < N; i++){ // Pick all vertices as destination for the above picked source 
            for (int j = 0; j < N; j++){  
                // If vertex k is on the shortest path from i to j, then update the value of adj[i][j]  
                if (adj[i][k] + adj[k][j] < adj[i][j])  
                    adj[i][j] = adj[i][k] + adj[k][j];  
            }  
        }  
    }
}  
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N = getint<int>();
    int M = getint<int>();
    int Q = getint<int>();
 
    vector<vector<long long>> adj(N+1, vector<long long>(N+1, INF));
    for(int a = 0; a < M; ++a)
    {
        long long s = getint<long long>();
        long long d = getint<long long>();
        long long p = getint<long long>();
        adj[s][d] = min(p, adj[s][d]);
        adj[d][s] = min(p, adj[d][s]);
    }

    floydWarshall(adj, N+1);
 
    string res = "";
    for(int a = 0; a < Q; ++a)
    {
        long long s = getint<long long>();
        long long d = getint<long long>();

        if(s == d){
            res += "0\n";
            continue;
        }
 
        long long search = min(adj[s][d], adj[d][s]);
 
        if(search != INF){
            res += to_string(search) + "\n";
        } else {
            res += "-1\n";
        }
    }
    cout << res;
}