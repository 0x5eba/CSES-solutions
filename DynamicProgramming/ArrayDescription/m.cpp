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

/*
8 5
0 0 3 4 0 0 0 1
3 4 3/4/5 2/3/4/5/6 1/2/3/4/5/6/7 1

valori tra 1 e m
dp[0] = 3
dp[1] = 4
dp[2] = 3, 4, 5
dp[3] = 2, 3, 4, 5
dp[4] = 1, 2, 3, 4, 5
dp[5] = 1

dp[0] = 3, 3
dp[1] = 4, 4
dp[2] = 3, 5
dp[3] = 2, 5
dp[4] = 1, 5
dp[5] = 1, 1
*/

int main() { 
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N = getint<int>(); 
    int M = getint<int>();

    vector<int> v(N);

    for(int a = 0; a < N; ++a){
        v[a] = getint<int>(); 
    }

    // nel pair metto il valore del primo e dell'ultimo numero
    vector<pair<int, int>> dp(N);
    int a = 0;
    if(v[0] != 0){
        dp[0] = make_pair(v[0], v[0]);
    } else {
        while(v[a] == 0){
            a++;
        }
    }

    for(; a < N; ++a){
        if(v[a] != 0){
            dp[a] = make_pair(v[a], v[a]);
        } else {
            // dp[a] = (dp[a-1][0] - 1) + dp[a-1] + (dp[a-1][dp[a].size()-1] + 1 )

            auto start = dp[a-1].first;
            auto end = dp[a-1].second;

            if(start - 1 > 0){
                start--;
            }
            if(end + 1 <= M){
                end++;
            }

            dp[a] = make_pair(start, end);
        }
    }

    // for(auto a : dp){
    //     cout << a.first << " " << a.second << endl;
    // }
    // cout << endl;

    long long sum = 0;

    for(int a = N-2; a >= 0; --a){

        auto start = dp[a+1].first;
        auto end = dp[a+1].second;

        if(dp[a].first == 0 && dp[a].second == 0){
            if(start - 1 > 0){
                start--;
            }
            if(end + 1 <= M){
                end++;
            }
            // cout << dp[a].first << " " << dp[a].second << endl;
            dp[a] = make_pair(start, end);
            sum += ((end-start)+1);
            sum %= MOD;
            continue;
        }

        if(dp[a].first == dp[a].second){
            // sum += 1;
            // sum %= MOD;
            continue;
        }

        start = max(dp[a].first, start - 1);
        start = max(start, 1);

        end = min(dp[a].second, end + 1);
        end = min(end, M);

        dp[a] = make_pair(start, end);
        sum += ((end-start)+1);
        sum %= MOD;

        
    }

    // for(auto a : dp){
    //     cout << a.first << " " << a.second << endl;
    // }
    cout << sum;
}