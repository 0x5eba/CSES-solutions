#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int,int> ii;
typedef long long ll;
const int mod = 1e9 + 7;
const ll inf = 3e18 + 5;
int add(int a, int b) { return (a += b) < mod ? a : a - mod; }
int mul(int a, int b) { return 1LL * a * b % mod; }

bool sortbysec(ii &a, ii &b) { 
    return (a.second < b.second); 
} 

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
    vector<ii> v(N);
    for(int a = 0; a < N; ++a){
        v[a].first = getint<int>();
        v[a].second = getint<int>();
    }
    sort(v.begin(), v.end(), sortbysec); 
    
    vector<int> ends(N);
    ends[0] = v[0].second;
    string res = "1";
    int c = 0;
    for(int a = 1; a < N; ++a){
        for(int b = 0; b < N; ++b){
            if (v[a].first > ends[b]){
                ends[b] = v[a].second;
                res += " " + to_string(b+1);
                c = max(c, b);
                break;
            }
        }
    }
    cout << c+1 << endl;
    cout << res << endl;
}