#include<bits/stdc++.h>
using namespace std;

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

inline bool byfirst(const pair<int,int> &a, const pair<int,int> &b) { 
    return (a.first < b.first); 
}

int main() { 
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N = getint<int>(); 
    int G = getint<int>(); 

    vector<int> v(N);
    for(int a = 0; a < N; ++a){
        v[a] = getint<int>(); 
    }

    for(int a = 0; a < G; ++a){
        int val = getint<int>(); 
        bool ok = true;
        for(int b = 0; b < N; ++b){
            if(v[b] >= val){
                cout << b+1 << " ";
                ok = false;
                v[b] -= val;
                break;
            }
        }
        if(ok){
            cout << 0 << " ";
        }
    }
}