#include<bits/stdc++.h> 
using namespace std; 

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#define MAX 1e9
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


int main() { 
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);;
    int N;
    cin >> N;
    vector<string> v(N);
    for(int a = 0; a < N; ++a){
        cin >> v[a];
    }

    if(v[N-1][N-1] == '*' || v[0][0] == '*'){
        cout << 0;
        return 0;
    }

    vector<vector<int>> dp(N, vector<int>(N));
    for(int a = 0; a < N; ++a){
        if(v[0][a] == '*')
            break;
        dp[0][a] = 1;
    }
    for(int a = 0; a < N; ++a){
        if(v[a][0] == '*')
            break;
        dp[a][0] = 1;
    }

    for(int a = 1; a < N; ++a){
        for(int b = 1; b < N; ++b){
            if(v[a][b] != '*'){
                dp[a][b] = (dp[a-1][b] + dp[a][b-1]) % MOD;
            }
        } 
    }

    cout << dp[N-1][N-1];
}