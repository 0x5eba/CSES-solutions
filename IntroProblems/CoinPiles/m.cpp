#include <iostream> 
using namespace std; 
#define ll long long
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

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

    while(N--){
        ll a = getint<ll>(); 
        ll b = getint<ll>(); 
        if(a%3 == 0 && b%3 == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}