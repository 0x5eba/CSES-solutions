#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvii vector<vector<pair<int, int>>>
#define vvl vector<vector<ll>>
#define vvll vector<vector<pair<ll, ll>>>
#define FOR(x, N) for(x = 0; x < N; ++x)
#define epsilon 1e-9
#define INF 3e18 + 5
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
template<class... Args>
inline void print(Args&&... args){
    ((cout << args << " "), ...) << "\n";
}
template<class T>
inline void parr(vector<T> arr){
    for(auto a : arr) cout << a << " ";
    cout << "\n";
}

int Q, N, M, a, b, c;

ll modpow(int x, int n) {
	if (n == 0) 
		return 1;
	ll u = modpow(x, n >> 1);
	u = (u*u)%MOD;
	if (n & 1) 
		u = (u*x)%MOD;
	return u;
}

// int modpow(int a, int b) {
//     a %= MOD;
//     ll result = 1;
//     while(b > 0){
//         if(b & 1) 
//             result = (result*a) % MOD;
//         a = (a*a) % MOD;
//         b >>= 1;
//     }
//     return result;
// }

int main() { 
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    N = getint<int>();
	while(N--){
		a = getint<int>();
		b = getint<int>();
		cout << modpow(a, b) << "\n";
	}
}