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

#define MAX 1e9

int minCoins(vector<int> &coins, int M) { 
    // int table[M+1]; 
    // table[0] = 0; 
    // for (int i=1; i<=M; i++) 
    //     table[i] = INT_MAX; 

    // // Compute minimum coins required for all values from 1 to M 
    // for (int i=1; i <= M; i++) { 
    //     // Go through all coins smaller than i 
    //     for(auto coin : coins){
    //         if (coin <= i) { 
    //             int sub_res = table[i-coin]; 
    //             if (sub_res != INT_MAX && sub_res + 1 < table[i]) 
    //                 table[i] = sub_res + 1; 
    //         } else {
    //             break;
    //         }
    //     }
    // } 
    
    int dp[M+1]; 
    dp[0] = 0;
    for (int x = 1; x <= M; x++) {
        dp[x] = MAX;
        for (auto c : coins) {
            if (x-c >= 0) {
                dp[x] = min(dp[x], dp[x-c]+1);
            }
        }
    }

    if(dp[M] == MAX)
        return -1;
    return dp[M]; 
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

    cout << minCoins(v, M); 
}