#include <bits/stdc++.h> 
using namespace std; 
  
// a structure to represent an edge in the graph 
struct Edge { 
    int src, dest; 
}; 
  
// a structure to represent a graph 
struct Graph { 
    // V-> Number of vertices, E-> Number of edges 
    int V, E; 
    // graph is represented as an array of edges 
    struct Edge* edge; 
}; 
  
struct subset { 
    int parent; 
    int rank; 
}; 
  
// Creates a graph with V vertices and E edges 
struct Graph* createGraph(int V, int E) 
{ 
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) ); 
    graph->V = V; 
    graph->E = E; 

    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) ); 
    return graph; 
} 
  
// A utility function to find set of an element i 
// (uses path compression technique) 
int find(struct subset subsets[], int i) 
{ 
    // find root and make root as parent of i (path compression) 
    if (subsets[i].parent != i) 
        subsets[i].parent = find(subsets, subsets[i].parent); 

    return subsets[i].parent; 
} 
  
// A function that does union of two sets of x and y 
// (uses union by rank) 
void Union(struct subset subsets[], int x, int y) 
{ 
    int xroot = find(subsets, x); 
    int yroot = find(subsets, y); 
  
    // Attach smaller rank tree under root of high rank tree 
    // (Union by Rank) 
    if (subsets[xroot].rank < subsets[yroot].rank) 
        subsets[xroot].parent = yroot; 
    else if (subsets[xroot].rank > subsets[yroot].rank) 
        subsets[yroot].parent = xroot; 
  
    // If ranks are same, then make one as root and increment 
    // its rank by one 
    else
    { 
        subsets[yroot].parent = xroot; 
        subsets[xroot].rank++; 
    } 
} 
  
// The main function to check whether a given graph contains cycle or not 
int isCycle( struct Graph* graph ) 
{ 
    int V = graph->V; 
    int E = graph->E; 
  
    // Allocate memory for creating V sets 
    struct subset *subsets = (struct subset*) malloc( V * sizeof(struct subset) ); 
  
    for (int v = 0; v < V; ++v) 
    { 
        subsets[v].parent = v; 
        subsets[v].rank = 0; 
    } 
  
    for(int e = 0; e < E; ++e) 
    { 
        int x = find(subsets, graph->edge[e].src); 
        int y = find(subsets, graph->edge[e].dest); 

        cout << x << " " << y << endl;
  
        // if (x == y) 
        //     return 1; 
  
        Union(subsets, x, y); 
    } 

    for (int v = 0; v < E; ++v) 
    { 
        cout << subsets[v].parent << endl;
    } 

    return 0; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    int V = 5, E = 4; 
    struct Graph* graph = createGraph(V, E); 
  
    // add edge 0-1 
    graph->edge[0].src = 0; 
    graph->edge[0].dest = 1; 
  
    // add edge 1-2 
    graph->edge[1].src = 1; 
    graph->edge[1].dest = 2; 
  
    // add edge 0-2 
    graph->edge[2].src = 0; 
    graph->edge[2].dest = 2; 

    graph->edge[3].src = 3; 
    graph->edge[3].dest = 4;

    isCycle(graph);
    return 0; 
} 