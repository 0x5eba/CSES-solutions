#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#define MOD 1000000007

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

struct FenwickTree {
    vector<long long> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<long long> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    long long sum(int r) {
        long long ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    long long sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }

    void print(){
        for(auto a : bit)
            cout << a << " ";
        cout << endl;
    }
};


// long long getSum(vector<long long> &BITree, int index){
//     int sum = 0;
//     index++;
//     while(index > 0){
//         sum += BITree[index];
//         index -= index & (-index);
//     }
//     return sum;
// }
// long long rangeSum(vector<long long> &BITree, int l, int r) {
//     return getSum(BITree, r) - getSum(BITree, l - 1);
// }

// void updateBIT(vector<long long> &BITree, int n, int index, int val) { 
//     index++; 
//     while (index <= n) { 
//         BITree[index] += val; 
//         index += index & (-index); 
//     } 
// } 
// void range_add(vector<long long> &BITree, int l, int r, int n, int val) {
//     updateBIT(BITree, n, l, val);
//     updateBIT(BITree, n, r + 1, -val);
// }

// vector<long long> constructBITree(vector<long long> &arr, int n){
//     vector<long long> BITree(n+1);
//     for(int a = 0; a < n; ++a){
//         int index = a+1;
//         while(index <= n){
//             BITree[index] += arr[a];
//             index += index & (-index);
//         }
//     }
//     return BITree;
// }


int main() { 
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N = getint<int>(); 
    int Q = getint<int>(); 

    auto BITree = FenwickTree(N);
    for(int a = 0; a < N; ++a){
        BITree.add(a, getint<int>());
    }

    for(int a = 0; a < Q; ++a){
        int l = getint<int>();
        int r = getint<int>();
        l--; r--;
        cout << BITree.sum(l, r) << endl;
    }
}