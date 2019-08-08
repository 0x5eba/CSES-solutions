#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#define ll long long
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

// Iterative Function to calculate (x^y)%p in O(log y)
ll power(ll x, ll y, ll p)
{
	ll res = 1; // Initialize result
	x = x % p; // Update x if it is more than or
	// equal to p
	while (y > 0) {
		// If y is odd, multiply x with result
		if (y & 1)
			res = (res * x) % p;
		// y must be even now
		y = y >> 1; // y = y/2
		x = (x * x) % p;
	}
	return res;
}

int main() { 
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N = getint<int>(); 
    
    cout << power(2, N, MOD);
}