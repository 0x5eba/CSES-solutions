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
    vector<int> v(N);
    for(int a = 0; a < N; ++a){
        v[a] = getint<int>();
    }
    set<ll> s;
    s.insert(v[0]);
    for(int a = 1; a < N; ++a){
        int curr = v[a];
        set<ll> s2 = s;
        for(auto elm : s2){
            s.insert(curr + elm);
        }
        s.insert(curr);
    }

    cout << s.size() << '\n';
    for(auto elm : s){
        cout << elm << " ";
    }

}