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

#define MAXN 900010
typedef long long ll;
/*
struct sdata {
    int ans;
    set<int> s;
};

sdata tree[MAXN];

sdata combine(sdata l, sdata r) {
    sdata res;
    merge(l.s.begin(), l.s.end(),
        r.s.begin(), r.s.end(),
        inserter(res.s, res.s.begin()));
    res.ans = res.s.size();
    // res.sum = l.sum + r.sum;
    // res.pref = max(l.pref, l.sum + r.pref);
    // res.suff = max(r.suff, r.sum + l.suff);
    // res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
    return res;
}

sdata make_data(int val, bool empty=false) {
    sdata res;
    if(empty){
        res.ans = 0;
        return res;
    }
    
    res.s.insert(val);
    res.ans = res.s.size();
    return res;
}
*/

struct sdata {
    vector<int> s;
};

sdata tree[MAXN];

sdata combine(sdata l, sdata r) {
    sdata res;
    copy(r.s.begin(), r.s.end(), back_inserter(res.s)); 
    copy(l.s.begin(), l.s.end(), back_inserter(res.s)); 
    return res;
}

sdata make_data(int val, bool empty=false) {
    sdata res;
    if(empty){
        return res;
    }
    res.s.emplace_back(val);
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
        return make_data(0, true);
    if (l == tl && r == tr) 
        return tree[v];
    int tm = (tl + tr) / 2;
    return combine(query(v*2, tl, tm, l, min(r, tm)), query(v*2+1, tm+1, tr, max(l, tm+1), r));
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
        int l = getint<int>();
        int r = getint<int>();
        l--;
        r--;

        auto s = query(1, 0, N-1, l, r).s;
        set<int> res;
        for(auto elm : s){
            res.insert(elm);
        }

        cout << res.size() << "\n";
    }
}