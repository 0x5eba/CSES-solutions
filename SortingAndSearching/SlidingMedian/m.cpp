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
    cin.tie(0);

    int N = getint<int>(); 
    int K = getint<int>(); 

    bool pari = false;
    int middle = (int)(K/2)+1;
    if(K%2 == 0){
        pari = true;
        middle = (int)(K/2);
    }

    middle--;

    multiset<int> s;
    queue<int> first_k_elm;

    for(int a = 0; a < K; ++a){
        int val = getint<int>(); 
        first_k_elm.push(val);
        s.insert(val);
    }

    if(pari){
        auto it1 = next(s.begin(), middle);
        auto it2 = next(s.begin(), middle+1);
        cout << min(*it1, *it2) << " ";
    } else {
        auto it = next(s.begin(), middle);
        cout << *it << " ";
    }
    
    s.erase(s.lower_bound(first_k_elm.front()));
    first_k_elm.pop();

    // cout << endl;
    // for(auto a : s){
    //     cout << a << endl;
    // }
    // return 0;
    
    for(int a = K; a < N; ++a){
        int val = getint<int>(); 
        s.insert(val);
        first_k_elm.push(val);

        if(pari){
            auto it1 = next(s.begin(), middle);
            auto it2 = next(s.begin(), middle+1);
            cout << min(*it1, *it2) << " ";
        } else {
            auto it = next(s.begin(), middle);
            cout << *it << " ";
        }

        s.erase(s.lower_bound(first_k_elm.front()));
        first_k_elm.pop();
    }
    return 0;

}