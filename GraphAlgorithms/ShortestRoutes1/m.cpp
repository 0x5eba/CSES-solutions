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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    long long N = getint<long long>();
    long long M = getint<long long>();

    vector<vector<pair<long long, long long>>> adj(N+1);
    for(long long a = 0; a < M; ++a)
    {
        long long s = getint<long long>();
        long long d = getint<long long>();
        long long p = getint<long long>();
        adj[s].push_back(make_pair(d, p));
    }

    vector<long long> dist(N+1, INF);
    priority_queue< pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>> > pq; 

    pq.push({0, 1});
    dist[1] = 0;
    
    while(!pq.empty())
    {
        auto front = pq.top(); 
        pq.pop();

        auto u = front.second;
        if(front.first > dist[u])
            continue;

        for(auto i : adj[u])
        {
            auto v = i.first;
            auto w = i.second;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }    
    }

    for(long long a= 1; a < N+1; ++a){
        if(dist[a] != INF)
            cout << dist[a] << " ";
    }
}