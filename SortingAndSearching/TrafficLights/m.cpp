#include<bits/stdc++.h> 
using namespace std; 
#define ll long long
  
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
    int M = getint<int>();
    set<pair<int, int>> s;
    /*
    3, 6, 2
    0 - - 3 4 - 6 7 8
    
    0 - 2, 4 - 8
    0 - 2, 4 - 5, 7 - 8
    0 - 1, 4 - 5, 7 - 8
    */
    for(int a = 0; a < M; ++a){
        auto val = getint<int>();

    }
}