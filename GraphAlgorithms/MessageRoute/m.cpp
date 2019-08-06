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

#define INF 1e9

void printPath(vector<int> &parent, int j) 
{ 
    if (parent[j] == - 1) 
        return; 
    printPath(parent, parent[j]); 
    cout << j << " "; 
} 

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    // ifstream input("input.txt");
    
    int N = getint<int>();
    int M = getint<int>();

    int source = 1;
    int destination = N;
    int result = 0;

    vector<vector<pair<int, int>>> adj(N+1);
    for(int a = 0; a < M; ++a)
    {
        int s = getint<int>();
        int d = getint<int>();
        adj[s].push_back(make_pair(d, 1));
        adj[d].push_back(make_pair(s, 1));
    }

    vector<int> dist(N+1, INF);
    vector<int> parent(N+1, -1);
    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq; 

    pq.push({0, source});
    dist[source] = 0;
    
    while(!pq.empty())
    {
        auto front = pq.top(); 
        pq.pop();

        auto u = front.second;
        if(u == destination){
            result = front.first + 1;
            cout << result << endl; 
            cout << 1 << " ";
            printPath(parent, N);
            return 0;
        }

        if(front.first > dist[u])
            continue;

        for(auto i : adj[u])
        {
            int v = i.first;
            int w = i.second;
            if (dist[v] > dist[u] + w)
            {
                parent[v] = u;
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }    
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}