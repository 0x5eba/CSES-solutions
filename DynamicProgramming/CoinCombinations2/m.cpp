#include<bits/stdc++.h> 
using namespace std; 
#define ll long long
  
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

// create a map to store solutions of subproblems
unordered_map<string, ll> lookup;

// Function to find the total number of distinct ways to get change of N from unlimited supply of coins in set S
ll nCoins(vector<int> &S, int n, int N){
	if (N == 0)
		return 1;
	if (N < 0 || n < 0)
		return 0;

	// construct a unique map key from dynamic elements of the input
	string key = to_string(n) + "|" + to_string(N);

	// if sub-problem is seen for the first time, solve it and store its result in a map
	if (lookup.find(key) == lookup.end()){
		// Case 1. include current coin S[n] in solution and recur
		// with remaining change (N - S[n]) with same number of coins
		ll include = nCoins(S, n, N - S[n]);

		// Case 2. exclude current coin S[n] from solution and recur
		// for remaining coins (n - 1)
		ll exclude = nCoins(S, n - 1, N);

		// assign total ways by including or excluding current coin
		lookup[key] = include + exclude;
	}

	// return solution to current sub-problem
	return lookup[key];
}

int main() { 
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N = getint<int>();
    int M = getint<int>();
    vector<int> v(N);
    for(int a = 0; a < N; ++a){
        v[a] = getint<int>();
    }
    sort(v.begin(), v.end());

    cout << nCoins(v, N-1, M);
}