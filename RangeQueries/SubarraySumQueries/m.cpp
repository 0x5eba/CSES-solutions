#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

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
#define MAXN 6000010
typedef long long ll;

struct sdata {
    ll sum, pref, suff, ans;
};

sdata tree[MAXN];

sdata combine(sdata l, sdata r) {
    sdata res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, r.sum + l.suff);
    res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
    return res;
}

sdata make_data(int val) {
    sdata res;
    res.sum = val;
    res.pref = res.suff = res.ans = max(0, val);
    return res;
}

void build(vector<int> &a, int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = make_data(a[tl]);
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        tree[v] = combine(tree[v*2], tree[v*2+1]);
    }
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        tree[v] = make_data(new_val);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        tree[v] = combine(tree[v*2], tree[v*2+1]);
    }
}

sdata query(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return make_data(0);
    if (l == tl && r == tr) 
        return tree[v];
    int tm = (tl + tr) / 2;
    return combine(query(v*2, tl, tm, l, min(r, tm)), 
                   query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

int main() { 
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N = getint<int>(); 
    int Q = getint<int>(); 

    vector<int> v(N);
    for(int a = 0; a < N; ++a){
        v[a] = getint<int>();
    }
    build(v, 1, 0, N-1);

    for(int a = 0; a < Q; ++a){
        int k = getint<int>();
        int u = getint<int>();
        k--;
        update(1, 0, N-1, k, u);
        cout << query(1, 0, N-1, 0, N-1).ans << "\n";
    }
}