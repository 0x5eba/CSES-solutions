#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int,int> ii;
typedef long long ll;
const int mod = 1e9 + 7;
const ll inf = 3e18 + 5;

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
    int T = getint<int>(); 
    vector<int> v(N);
    for(int a = 0; a < N; ++a){
        v[a] = getint<int>();
    }
    sort(v.begin(), v.end()); 

    int c = 0;
    vector<long long> multi(N, 0);
    
    while(c != T){
        int a = 0;
        bool done = false;
        while(a < N-1){
            long long sum_a = multi[a] + v[a];
            long long sum_a_1 = multi[a+1] + v[a+1];
            if(sum_a <= sum_a_1){
                multi[a] = sum_a;
                c++;
                done = true;
                break;
            } 
            if(sum_a > sum_a_1){
                // multi[a+1] = sum_a_1;
                a++;
            }
        }
    }

}