#include<bits/stdc++.h> 

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

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

#define MOD 1000000007
/*
count[0] = 1;
for (int x = 1; x <= n; x++) {
    for (auto c : coins) {
        if (x-c >= 0) {
            count[x] += count[x-c];
        }
    }
}
*/

const int MAXN = 100, MAXX = 1e6;
int c[MAXN];
long long dp[MAXX + 1] = {0};

int main() { 
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N = getint<int>();
    int M = getint<int>();
    for(int a = 0; a < N; ++a){
        c[a] = getint<int>();
    }
    sort(c, c + N);

    dp[0] = 1;
    for (int i = c[0]; i <= M; ++i) {
        for (int j = 0; j < N && c[j] <= i; ++j)
            dp[i] += dp[i - c[j]];

        for(int a = 0; a <= M; ++a){
            cout << dp[a] << " ";
        }
        cout << endl;
        dp[i] %= MOD;
    }

    for(int a = 0; a <= M; ++a){
        cout << dp[a] << " ";
    }

    cout << dp[M]; 
}