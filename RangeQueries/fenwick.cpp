#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct FenwickTree {
    vector<ll> bit; 
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    // FenwickTree(vector<ll> a) : FenwickTree(a.size()) {
    //     for (size_t i = 0; i < a.size(); i++)
    //         update(i, a[i]); // puo' essere update(i, i, a[i])
    // }

    ll query(int r) {
        ll ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    ll query(int l, int r) {
        return query(r) - query(l - 1);
    }

    void update(int idx, int val) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += val;
    }

    void update(int l, int r, int val) {
        update(l, val);
        update(r + 1, -val);
    }

    void print(){
        for(auto a : bit)
            cout << a << " ";
        cout << endl;
    }
};