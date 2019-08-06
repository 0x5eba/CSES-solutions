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
    vector<long long> v(N);
    for(int a = 0; a < N; ++a){
        v[a] = getint<long long>();
    }

    long long max_so_far = v[0]; 
    long long curr_max = v[0]; 
    for (int i = 1; i < v.size(); i++) { 
        curr_max = max(v[i], curr_max+v[i]); 
        max_so_far = max(max_so_far, curr_max); 
    } 
    cout << max_so_far;
}