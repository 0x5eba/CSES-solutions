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

    vector<int> v;
    queue<int> first_k_elm;

    for(int a = 0; a < K; ++a){
        int val = getint<int>(); 
        first_k_elm.push(val);
        v.push_back(val);
    }
    sort(v.begin(), v.end());

    // if(pari){
    //     cout << min(v[middle], v[middle+1]) << " ";
    // } else {
    //     cout << v[middle] << " ";
    // }

    auto pos = lower_bound(v.begin(), v.end(), first_k_elm.front()) - v.begin();
    v.erase(v.begin() + pos);
    first_k_elm.pop();

    // cout << endl;
    // for(auto a : v){
    //     cout << a << endl;
    // }
    // return 0;

    for(int a = K; a < N; ++a){
        int val = getint<int>(); 
        v.push_back(val);
        first_k_elm.push(val);

        int middleone = v[middle];
        cout << middleone << endl;
        if(val > middleone){
            middle--;
        } else {
            middle++;
        }

        // sort(v.begin(), v.end());

        // if(pari){
        //     cout << min(v[middle], v[middle+1]) << " ";
        // } else {
        //     cout << v[middle] << " ";
        // }

        auto pos = lower_bound(v.begin(), v.end(), first_k_elm.front()) - v.begin();
        v.erase(v.begin() + pos);
        first_k_elm.pop();
    }
    return 0;

}