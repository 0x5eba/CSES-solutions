#include <vector>
#include <iostream>
#include <algorithm>

using namespace std; 

int main() { 
    long long N, M;
    cin >> N >> M; 
    vector<int> h(N);
    // long long *t = new long long[M];
    for(int a = 0; a < N; ++a)
        cin >> h[a];
    sort(h.begin(), h.end()); 
    for(int a = 0; a < M; ++a){
        long long val;
        cin >> val;
        long long idx = *upper_bound(h.begin(), h.end(), val);
        cout << val << endl;
        cout << idx << endl;
        // cout << h[idx] << endl;
        // h.erase(h.begin() + idx);
    }    

    return 0; 
}