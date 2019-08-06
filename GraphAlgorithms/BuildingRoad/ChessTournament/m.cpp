#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <numeric>

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
    vector<int> v(N);
    for(int a = 0; a < N; ++a){
        v[a] = getint<int>();
    }

    vector<string> res;
    int b = 1;
    for(int a = 0; a < N; ++a){
        while(v[a] > 0){
            if(v[a] == 0){
                break;
            }
            if(v[b] == 0){
                b++;
                continue;
            }
            v[b]--;
            v[a]--;
            res.push_back(to_string(a+1) + " " + to_string(b+1));
        }
    }

    for(auto a : v){
        cout << a << " ";
    }

    // if(accumulate(v.begin(),v.end(),0) != 0){
    //     cout << "IMPOSSIBLE";
    //     return 0;
    // }
    cout << res.size() << endl;
    for(auto s: res)
        cout << s << endl;

}