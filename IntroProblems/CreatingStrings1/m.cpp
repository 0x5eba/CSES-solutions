#include<bits/stdc++.h>
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
    // cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    sort(s.begin(), s.end());

    vector<string> v;
    int c = 0;
    do {
        v.emplace_back(s);
        c++;
    } while(next_permutation(s.begin(), s.end()));

    cout << c << '\n';
    for(auto a : v){
        cout << a << '\n';
    }
}