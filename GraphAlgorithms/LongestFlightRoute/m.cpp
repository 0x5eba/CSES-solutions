#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#define NINF INT_MIN
#define INF 3e18

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


class AdjListNode
{
    int v;        
    int weight;    
public:
    AdjListNode(int _v, int _w){
        v = _v;
        weight = _w;
    }
    int getV(){
        return v;
    }
    int getWeight(){
        return weight;
    }
};


// Class to represent a graph using adjacency list representation
class Graph{
    int V; // No. of vertices’
    list<AdjListNode> *adj;
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
public:
    Graph(int V);
    void addEdge(int u, int v, int weight);
    void longestPath(int s);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<AdjListNode> [V];
}

void Graph::addEdge(int u, int v, int weight)
{
    AdjListNode node(v, weight);
    adj[u].push_back(node);
}

void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
{
    visited[v] = true;
    for(auto node : adj[v]){
        if (!visited[node.getV()])
            topologicalSortUtil(node.getV(), visited, Stack);
    }
    // Push current vertex to stack which stores topological sort
    Stack.push(v);
}

// The function to find longest distances from a given vertex. It uses
void Graph::longestPath(int s)
{
    stack<int> Stack;
    int dist[V];

    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);

    for (int i = 0; i < V; i++)
        dist[i] = NINF;
    dist[s] = 0;

    vector<int> parent(V);

    while(!Stack.empty()){
        // Get the next vertex from topological order
        int u = Stack.top();
        Stack.pop();
        // Update distances of all adjacent vertices
        if (dist[u] != NINF){
            for(auto node : adj[u]){
                if (dist[node.getV()] < dist[u] + node.getWeight()){
                    parent[node.getV()] = u;
                    dist[node.getV()] = dist[u] + node.getWeight();
                }
            }
        }
    }

    if(dist[V-1] != NINF){
        cout << dist[V-1]+1 << endl;

        int found = parent[V-1];
        vector<int> result;
        result.push_back(V-1);
        while(found != 0){
            result.push_back(found);
            found = parent[found];
        }

        reverse(result.begin(), result.end());

        for(auto a : result)
            cout << a << " ";
    } else {
        cout << "IMPOSSIBLE\n";
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N = getint<int>();
    int M = getint<int>();

    Graph g(N+1);

    for(int a = 0; a < M; ++a)
    {
        int s = getint<int>();
        int d = getint<int>();
        g.addEdge(s, d, 1);
    }

    g.longestPath(1);

    return 0;
}