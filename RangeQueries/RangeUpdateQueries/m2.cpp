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

#define MAXN 6000010
typedef long long ll;
ll tree[MAXN];
ll lazy[MAXN];

int N;
void propaga(int inx, int cnt_num){
    if (lazy[inx]){
        tree[inx] += lazy[inx]*cnt_num;
        
        lazy[inx*2] += lazy[inx];
        lazy[inx*2+1] += lazy[inx];
        lazy[inx] = 0;
    }
}

void update(int tl, int tr, ll val,int l = 0, int r = N, int inx = 1){
    propaga(inx,r-l);
    // tutto fuori
    if (tr <= l || tl >= r || r <= l)
        return;
    // att dentro target
    int cnt_num = r-l;

    if (tl <= l && tr >= r){
        lazy[inx] += val;
        propaga(inx,cnt_num);
        return;
    }
    propaga(inx, cnt_num);
    int mid = (l+r)/2;
    update(tl,tr,val,l,mid,inx*2);
    update(tl,tr,val,mid,r,inx*2+1);
    tree[inx] = tree[inx*2]+tree[inx*2+1];
}

ll query(int tl, int tr, int l = 0, int r = N, int inx = 1){
    propaga(inx, r-l);

    // tutto fuori
    if (tr <= l || tl >= r)
        return 0;

    // att dentro target
    if (tl <= l && tr >= r)
        return tree[inx];

    int mid = (l+r)/2;
    return query(tl,tr,l,mid,inx*2)+query(tl,tr,mid,r,inx*2+1);
}

int main() { 
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    N = getint<int>(); 
    int Q = getint<int>(); 

    // memset(tree,0,sizeof tree);
    // memset(lazy,0,sizeof lazy);

    for(int a = 0; a < N; ++a){
        auto val = getint<int>();
        update(a, a+1, val);
    }

    for(int a = 0; a < Q; ++a){
        int q = getint<int>();
        
        if(q == 1){
            int l = getint<int>();
            int r = getint<int>();
            int u = getint<int>();
            l--;
            update(l, r, u);
        } else {
            int k = getint<int>();
            k--;
            cout << query(k, k+1) << endl;
        }
    }
}