#include<bits/stdc++.h>
using namespace std;

struct secure_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; 
        return x ^ (x >> 31); 
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); 
        return splitmix64(x + FIXED_RANDOM); 
    } 
};
template<typename T> using V = vector<T>;
template<typename T, typename U> using umap = unordered_map<T,U,secure_hash>; // umap<int,int> m;
template<typename T> using uset = unordered_set<T,secure_hash>;
template<typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using max_heap = priority_queue<T>;

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
    int X = getint<int>();

    umap<int,int> m;
    vector<int> v(N);
    for(int b = 0; b < N; ++b){
        int val = getint<int>();
        m[val] = b;
        v[b] = val;
    }
    
    for(int a = 0; a < N; ++a){
        int base = v[a];
        for(int b = a+1; b < N; ++b){
            int val = X - (v[b] + base);
            if(m.find(val) != m.end()){
                if(m[val] == a || m[val] == b)
                    continue;
                cout << a+1 << " " << b+1 << " " << m[val]+1;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";
}