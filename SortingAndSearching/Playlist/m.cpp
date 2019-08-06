#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

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

    set<int> s; 
    vector<int> v;
    int curr_max = 0;
    int tot_max = 0;
    for(int a = 0; a < N; ++a){
        int val = getint<int>();
        if(s.find(val) != s.end()){
            int b = 0;
            s.erase(v[b]);
            while(true){
                if(v[b] == val){
                    break;
                }
                b++;
                s.erase(v[b]);
            }

            v.erase(v.begin() + 0, v.begin() + (b+1));
            
            curr_max -= (b+1);

            // cout << curr_max << " " << b << endl;
        } 
        s.insert(val);
        v.push_back(val);
        curr_max++;
        tot_max = max(curr_max, tot_max);
    }
    cout << tot_max;
}