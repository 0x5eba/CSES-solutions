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

int maxDigit(int N){
	int ret = 0;
	while(N > 0){
		ret = max(ret, N % 10);
		N /= 10;
	}
	return ret;
}

int main() { 
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N = getint<int>();
    vector<int> dp(N+1, MAX);
    dp[0] = 0;
    for(int a = 1; a < 10; ++a){
        dp[a] = 1;
    }
    for(int a = 10; a <= N; ++a){
        string num = to_string(a);
        for(auto s : num){
            int int_s = s - 48;
            dp[a] = min(dp[a], dp[a-int_s]+1); 
        }
    }

    // while(N > 0){
	// 	N -= maxDigit(N);
	// 	ans++;
	// }
	// cout << ans;

    cout << dp[N];
}