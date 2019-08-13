#include<iostream>
#define MAX 100005
 
using namespace std;
 
int n, x, c;
bool dp[MAX];
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> n; 
    dp[0] = 1;

	for(int i=0;i<n;i++) {
		cin >> x;
		for(int j=MAX;j>=0;j--)
			if(dp[j] && j+x<=MAX) {
				if(!dp[j+x]) c++;
				dp[j+x] = 1;
			}
	}

	cout << c << "\n";
	for(int i=1;i<=MAX;i++) 
        if(dp[i]) 
            cout << i << " ";
	return 0;
}