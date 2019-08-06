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


vector<long long> result;
long long maxElm = 0;
void printPath(vector<long long> &parent, vector<vector<pair<long long, long long>>> &adj, long long j) 
{ 
    if (parent[j] == -1) 
        return; 
    printPath(parent, adj, parent[j]); 

    for(auto a : adj[parent[j]]){
        if(a.first == j){
            result.push_back(a.second);
            maxElm = max(maxElm, a.second);
            break;
        }
    }
    // cout << j << " " << parent[j] << endl;
} 

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N = getint<int>();
    int M = getint<int>();

    long long source = 1;
    long long destination = N;

    vector<vector<pair<long long, long long>>> adj(N+1);
    for(int a = 0; a < M; ++a)
    {
        int s = getint<int>();
        int d = getint<int>();
        int p = getint<int>();
        adj[s].push_back(make_pair(d, p));
    }

    vector<long long> dist(N+1, INF);
    vector<long long> parent(N+1, -1);
    priority_queue< pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>> > pq; 

    pq.push({0, source});
    dist[source] = 0;

    while(!pq.empty())
    {
        auto front = pq.top(); 
        pq.pop();

        auto u = front.second;
        if(u == destination){
            printPath(parent, adj, N);
            long long sum = 0;
            bool done = true;
            for(auto elm : result){
                if(elm == maxElm && done){
                    sum += round(maxElm/2);
                    done = false;
                } else {
                    sum += elm;
                }
            }
            cout << sum << endl;
            return 0;
        }

        if(front.first > dist[u])
            continue;

        for(auto i : adj[u])
        {
            auto v = i.first;
            auto w = i.second;
            if (dist[v] > dist[u] + w)
            {
                parent[v] = u;
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }    
    }
}