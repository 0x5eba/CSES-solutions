#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#define MOD 1000000007

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

int editDistDP(string s1, string s2, int m, int n){
    // vector<vector<int>> dp(m+1, vector<int>(n+1));
    int dp[m+1][n+1];
    
    for(int a = 0; a <= m; ++a){
        for(int b = 0; b <= n; ++b){
            if(a == 0)
                dp[a][b] = b;
            else if(b == 0)
                dp[a][b] = a;
            else if(s1[a-1] == s2[b-1])
                dp[a][b] = dp[a-1][b-1];
            else
                dp[a][b] = 1 + min(min(dp[a][b-1], dp[a-1][b]), dp[a-1][b-1]);
        }
    }
    return dp[m][n];
}

int main() { 
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    cout << editDistDP(s1, s2, s1.length(), s2.length());
}