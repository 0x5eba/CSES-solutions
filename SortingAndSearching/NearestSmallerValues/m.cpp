#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef long long ll;

bool mysort(ii &a, ii &b) { 
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
    vector<int> v(N);
    for(int a = 0; a < N; ++a){
        v[a] = getint<int>(); 
    }

    stack<ii> S; 
    for (int i=0; i<N; i++) 
    { 
        // Keep removing top element from S while the top 
        // element is greater than or equal to arr[i] 
        while (!S.empty() && S.top().first >= v[i]) 
            S.pop(); 

        // If all elements in S were greater than arr[i] 
        if (S.empty()) 
            cout << "0 "; 
        else  //Else print the nearest smaller element 
            cout << S.top().second+1 << " "; 

        // Push this element 
        S.push(make_pair(v[i], i)); 
    } 

}