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

int Q, N, M, a, b;

int modFact(int n){ 
    ll result = 1; 
    for (int i = 1; i <= n; i++) 
        result = (result * i) % MOD; 
    return result; 
} 

int main() { 
    ios::sync_with_stdio(0);

    string s;
    cin >> s;
    
	vi letters(26, 0);
	for(auto a : s){
		letters[a - 97]++;
	}

	parr(letters);

	
	// ll res = 1;
	// for(auto a : letters){
	// 	if(a == 0)
	// 		continue;
	// 	res = (res * modFact(a)) % MOD;
	// }
	// cout << (N / res) % MOD;

	ll N = 1;
	for (int i = 1; i <= s.length(); i++) 
        N = (N * i);

	ll res = 1;
	for(auto a : letters){
		if(a == 0 || a == 1)
			continue;
		res = (res * a) % MOD;
	}
	cout << (N / res) % MOD;
}	