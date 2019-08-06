#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef pair<int,int> ii;
typedef long long ll;
const int mod = 1e9 + 7;
const ll inf = 3e18 + 5;
int add(int a, int b) { return (a += b) < mod ? a : a - mod; }
int mul(int a, int b) { return 1LL * a * b % mod; }

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
    if(X == 1000000000){
        cout << "IMPOSSIBLE";
        return 0;
    }

    unordered_map<int, int> umap; 
    for(int a = 0; a < N; ++a){
        int val = getint<int>();
        if(umap.find(val) != umap.end()){
            cout << umap[val]+1 << " " << a+1;
            return 0;
        }
        umap[X-val] = a;
    }
    cout << "IMPOSSIBLE";
}