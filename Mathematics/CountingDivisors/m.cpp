#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvii vector<vector<pair<int, int>>>
#define vvl vector<vector<ll>>
#define vvll vector<vector<pair<ll, ll>>>
#define FOR(x, N) for(x = 0; x < N; ++x)
#define epsilon 1e-9
#define INF 3e18 + 5
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
template<class... Args>
inline void print(Args&&... args){
    ((cout << args << " "), ...) << "\n";
}
template<class T>
inline void parr(vector<T> arr){
    for(auto a : arr) cout << a << " ";
    cout << "\n";
}
/*
void SieveOfEratosthenes(ll n, bool prime[], bool primesquare[], ll a[]) { 
    // Create a boolean array "prime[0..n]" and 
    // initialize all entries it as true. A value 
    // in prime[i] will finally be false if i is 
    // Not a prime, else true. 
    for (ll i = 2; i <= n; i++) 
        prime[i] = true; 
  
    // Create a boolean array "primesquare[0..n*n+1]" 
    // and initialize all entries it as false. A value 
    // in squareprime[i] will finally be true if i is 
    // square of prime, else false. 
    for (ll i = 0; i <= (n * n + 1); i++) 
        primesquare[i] = false; 
  
    // 1 is not a prime number 
    prime[1] = false; 
  
    for (ll p = 2; p * p <= n; p++) { 
        // If prime[p] is not changed, then 
        // it is a prime 
        if (prime[p] == true) { 
            // Update all multiples of p 
            for (ll i = p * 2; i <= n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    ll j = 0; 
    for (ll p = 2; p <= n; p++) { 
        if (prime[p]) { 
            // Storing primes in an array 
            a[j] = p; 
  
            // Update value in primesquare[p*p], 
            // if p is prime. 
            primesquare[p * p] = true; 
            j++; 
        } 
    } 
} 
  
// Function to count divisors 
ll countDivisors(ll n) { 
    // If number is 1, then it will have only 1 
    // as a factor. So, total factors will be 1. 
    if (n == 1) 
        return 1; 
  
    bool prime[n * 2], primesquare[n * n + 1]; 

    cout << "ok1\n"; 
  
    ll a[n]; // for storing primes upto n 
  
    // Calling SieveOfEratosthenes to store prime 
    // factors of n and to store square of prime 
    // factors of n 
    SieveOfEratosthenes(n, prime, primesquare, a); 

    cout << "ok2\n";
  
    // ans will contain total number of distinct 
    // divisors 
    ll ans = 1; 
  
    // Loop for counting factors of n 
    for (ll i = 0;; i++) { 
        // a[i] is not less than cube root n 
        if (a[i] * a[i] * a[i] > n) 
            break; 
  
        // Calculating power of a[i] in n. 
        ll cnt = 1; // cnt is power of prime a[i] in n. 
        while (n % a[i] == 0) // if a[i] is a factor of n 
        { 
            n = n / a[i]; 
            cnt = cnt + 1; // incrementing power 
        } 
  
        // Calculating number of divisors 
        // If n = a^p * b^q then total divisors of n 
        // are (p+1)*(q+1) 
        ans *= cnt; 
    } 
  
    // if a[i] is greater than cube root of n 
  
    // First case 
    if (prime[n]) 
        return ans*2;
    // Second case 
    else if (primesquare[n]) 
        return ans*3;
    // Third casse 
    else if (n != 1) 
        return ans*4; 
    return ans; // Total divisors 
} 
*/

ll countDivisors(int n) { 
    ll cnt = 0; 
    int s = sqrt(n);
    for (int i = 1; i <= s; i++) { 
        if (n % i == 0) { 
            // If divisors are equal, count only one 
            if (n / i == i) 
                cnt++; 
            else // Otherwise count both 
                cnt += 2; 
        } 
    } 
    return cnt; 
} 

int main() { 
    // ifstream cin("input.txt");
    int N = getint<int>();
    // cin >> N;
	while(N--){
		int num = getint<int>();
        // cin >> num;
		cout << countDivisors(num) << "\n";
	}
} 