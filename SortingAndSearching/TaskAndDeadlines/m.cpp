#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef pair<int,int> ii;
typedef long long ll;
const int mod = 1e9 + 7;
const ll inf = 3e18 + 5;

bool sortbyfirst(ii &a, ii &b) { 
    return (a.first < b.first); 
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
    sort(v.begin(), v.end(), sortbyfirst);

    long long res = 0;
    long long tempo_trascorso = 0;
    for(auto a : v){
        tempo_trascorso += a.first;
        res += (a.second - tempo_trascorso);
    }
    cout << res << endl;
}