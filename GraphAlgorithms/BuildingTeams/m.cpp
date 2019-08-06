#include <bits/stdc++.h>
 
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

#define MAX 1000000

int color[MAX], visited[MAX];
vector<int> graph[MAX];

bool bfs(int start)
{
    queue<int> q;
    q.push(start);
    color[start] = 1;
    visited[start] = 1;

    while(!q.empty())
    {
        auto u = q.front(); 
        q.pop();

        for(auto edge : graph[u]){
            if(color[u] == color[edge]){
                return false;
            }
            if(visited[edge] == 0){
                visited[edge] = 1;
                color[edge] = 3 - color[u]; // 1 or 2 are the colors
                q.push(edge);
            }
        }
    }
    return true;
}

bool is_bipartite(int N)
{
    for(int i=0; i < N; i++)
        if (visited[i] == 0 && !bfs(i))
            return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int i,j, x, y;
    int N = getint<int>(); N++;
    int M = getint<int>();
    
    for(i=0; i<M; i++)
    {
        x = getint<int>();
        y = getint<int>();
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    if(is_bipartite(N))
        for (j=1; j<N; j++)
            cout << color[j] << " ";
    else 
        cout << "IMPOSSIBLE\n";

    return 0;
}