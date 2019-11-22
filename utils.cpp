#include<bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#define PARR(arr) for(auto a : arr) cout << a << " ";

struct secure_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); 
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM); 
    } 
};
template<typename T> using V = vector<T>;
template<typename T, typename U> using umap = unordered_map<T,U,secure_hash>; // umap<int,int> m;
template<typename T> using uset = unordered_set<T,secure_hash>;
template<typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using max_heap = priority_queue<T>;

#define INF 3e18 + 5
#define MOD 1000000007

int ad(int a, int b, int mod = MOD) { return (a + b) % mod; }
int sub(int a, int b, int mod = MOD) { return (a - b + mod) % mod; }
int mul(int a, int b, int mod = MOD) { return (long long)a * b % mod; }

int AD(int &a, int b, int mod = MOD) { return a = ad(a, b, mod); }
int SUB(int &a, int b, int mod = MOD) { return a = sub(a, b, mod); }
int MUL(int &a, int b, int mod = MOD) { return a = mul(a, b, mod); }
 
int po(int b, int p, int mod = MOD) { return !p ? 1 : mul(po(mul(b, b, mod), p / 2, mod), p & 1 ? b : 1, mod); }
int inv(int b, int mod = MOD) { return po(b, mod - 2, mod); }

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

    int N = getint<int>(); 

    for(int a = 0; a < N; ++a){
        
    }
}