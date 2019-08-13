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


int main() { 
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // ifstream input("test_input.txt");
    // int N, Q;
    // input >> N >> Q;

    int N = getint<int>();
    int Q = getint<int>();
    vector<int> adj(N+1, -1);

    // Successor paths problem pg 164
    
    for(int a = 0; a < N-1; ++a){
        int boss = getint<int>();
        // int boss;
        // input >> boss;
        int employee = a+2;
        adj[employee] = boss;
    } 
    adj[1] = 0;

    // for(int employee = 1; employee < N+1; ++employee){
    //     cout << employee << " -> " << adj[employee] << endl;
    // }
    /*
        1 -> 0
        2 -> 1
        3 -> 1
        4 -> 3
        5 -> 3
    */

    // vector<vector<int>> dp(N+3, vector<int>(262150, -1));
    // for(int employee = 0; employee < N+3; ++employee){
    //     if(adj[employee] == -1)
    //         continue;
    //     // cout << employee << endl;
    //     dp[employee][1] = adj[employee];
    //     for(int a = 2; a <= N; a <<= 1){ // powers of 2 until N

    //         int prev = dp[employee][a >> 1]; 

    //         for(int b = a >> 1; b <= a; ++b){
    //             // cout << a << " " << b << endl;
    //             if(prev == 0){
    //                 dp[employee][b] = -1;
    //                 break;
    //             }
    //             dp[employee][b] = prev;
    //             prev = adj[prev];
    //         }
    //     }  
    // }


    vector<vector<int>> dp(N+1, vector<int>(20)); // 2**18 = 262144 = 2*10^5
    for(int employee = 1; employee < N+1; ++employee){

        dp[employee][0] = adj[employee];
        for(int a = 1; a < 20; ++a){
            int prev = dp[employee][a-1];  // for(int b = 1 << (a-1); b < (1 << a); ++b){
            prev = dp[prev][a-1]; 
            if(!prev)
                break;
            dp[employee][a] = prev;
        }
    }

    for(int a = 0; a < Q; ++a){
        int emplyee = getint<int>();
        int level = getint<int>();
        // int emplyee, level;
        // input >> emplyee >> level;

        bitset<20> bit(level);
        for(int b = 0; b < 20; ++b){
            if(bit[b] == 1){
                if(!emplyee) 
                    break;
                // int idx = 1 << b; // pow(2, b)
                emplyee = dp[emplyee][b]; // succ(4,11) = succ(succ(succ(4,8),2),1) = 5
            }
        }
        if(!emplyee)
            emplyee = -1;
        cout << emplyee << "\n";
    } 
}