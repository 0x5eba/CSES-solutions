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
    
    int end = v[0].second;
    int c = 1;
    for(int a = 1; a < N; ++a){
        if(v[a].first >= end){
            end = v[a].second;
            c++;
        }
    }
    cout << c;
}