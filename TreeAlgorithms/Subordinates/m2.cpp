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

vector<int> nChilds;
vector<vector<int>> adj;

void count_subnode(int s, int e) {
    nChilds[s] = 1;
    for(auto child : adj[s]){
        if(child == e) 
            continue;
        count_subnode(child, s);
        nChilds[s] += nChilds[child];
    }
}

int main() { 
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N = getint<int>();
    nChilds.resize(N+3);
    adj.resize(N+3);
    
    for(int a = 0; a < N-1; ++a){
        int val = getint<int>();
        int currNode = a+2;
        adj[val].emplace_back(currNode);
    } 

    count_subnode(1, 0);

    for(int a = 1; a <= N; ++a){
        cout << nChilds[a]-1 << " ";
    }
}