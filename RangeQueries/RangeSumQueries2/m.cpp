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

int main() { 
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N = getint<int>(); 
    int Q = getint<int>(); 

    vector<long long> v(N);
    for(int a = 0; a < N; ++a){
        v[a] = getint<int>();
    }
    auto BITree = FenwickTree(v);

    for(int a = 0; a < Q; ++a){
        int q = getint<int>();
        int l = getint<int>();
        int r = getint<int>();
        l--;

        if(q == 1){
            auto diff = v[l] - r;
            v[l] = r;
            BITree.add(l, -diff);
        } else {
            r--;
            cout << BITree.sum(l, r) << endl;
        }
    }
}