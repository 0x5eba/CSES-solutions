#include <bits/stdc++.h> 
using namespace std; 
  
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

long long optimalStrategyOfGame(vector<int> &arr, int n) 
{ 
    long long table[n][n]; 
  
    for (int gap = 0; gap < n; ++gap) { 
        for (int i = 0, j = gap; j < n; ++i, ++j) { 
            // Here x is value of F(i+2, j), y is F(i+1, j-1) and z is F(i, j-2)
            auto x = ((i + 2) <= j) ? table[i + 2][j] : 0; 
            auto y = ((i + 1) <= (j - 1)) ? table[i + 1][j - 1] : 0; 
            auto z = (i <= (j - 2)) ? table[i][j - 2] : 0; 
  
            table[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z)); 
        } 
    } 
  
    return table[0][n - 1]; 
} 


int main() { 
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N = getint<int>(); 

    vector<int> v(N);
    for(int a = 0; a < N; ++a){
        v[a] = getint<int>(); 
    }

    cout << optimalStrategyOfGame(v, N);
}