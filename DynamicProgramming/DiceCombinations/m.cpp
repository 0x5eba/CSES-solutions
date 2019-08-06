#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef long long ll;

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
  
long findWays(int d, int s) { 
    long mem[d + 1][s + 1]; 
    memset(mem,0,sizeof mem); 
    mem[0][0] = 1; 

    // Iterate over dices 
    for (int i = 1; i <= d; i++) { 
        // Iterate over sum 
        for (int j = i; j <= s; j++) { 
            // The result is obtained in two ways, pin the current dice and spending 1 of the value, 
            // so we have mem[i-1][j-1] remaining combinations, to find the remaining combinations we 
            // would have to pin the values ??above 1 then we use mem[i][j-1] to sum all combinations 
            // that pin the remaining j-1's. But there is a way, when "j-f-1> = 0" we would be adding 
            // extra combinations, so we remove the combinations that only pin the extrapolated dice face and 
            // subtract the extrapolated combinations. 
            mem[i][j] = mem[i][j - 1] + mem[i - 1][j - 1]; 
            if (j - 3 - 1 >= 0) 
                mem[i][j] -= mem[i - 1][j - 3 - 1]; 
        } 
    } 
    return mem[d][s]; 
} 

int main() { 
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int M = getint<int>(); 
	cout << findWays(6, M);
}