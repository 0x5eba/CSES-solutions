#include<bits/stdc++.h>
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

int knapSack(int W, vector<int> &wt, vector<int> &val, int n) { 
    int i, w; 
    int K[n+1][W+1]; 
  
    for (i = 0; i <= n; i++) 
    { 
        for (w = 0; w <= W; w++) 
        { 
            if (i==0 || w==0) 
                K[i][w] = 0; 
            else if (wt[i-1] <= w) 
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]); 
            else
                K[i][w] = K[i-1][w]; 
        } 
    } 

    return K[n][W]; 
}

int main() { 
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N = getint<int>(); 
    int W = getint<int>();

    vector<int> values(N);
    vector<int> weight(N);

    for(int a = 0; a < N; ++a){
        weight[a] = getint<int>(); 
    }
    for(int a = 0; a < N; ++a){
        values[a] = getint<int>(); 
    }

    vector<int> dp(W+1);
    for(int a = 0; a < N; ++a)
        for (int b = W; b >= weight[a]; b--)
            dp[b] = max(dp[b], dp[b - weight[a]] + values[a]);

    cout << dp[W];
}