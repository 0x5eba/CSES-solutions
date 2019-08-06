#include<bits/stdc++.h>
using namespace std;
 
#define md (st+en) >>1
#define lc (nd<<1) +1
#define rc (nd<<1) +2
 
const int N = 2e5+5;
int n,q;
long long a[N],val;
long long tree[4*N],lazy[4*N];
 
void build(int st,int en, int nd){
	if(st == en){
		tree[nd] = a[st];
	}
	else{
		int mid = md;
		build(st,mid,lc);
		build(mid+1,en,rc);
		tree[nd] = 0;
	}
}
 
void updater(int st, int en ,int nd, int l,int r){
	if(l <= st && en <= r){
		lazy[nd] += val;
	}
	else{
		if(lazy[nd]){
			lazy[lc] += lazy[nd];
			lazy[rc] += lazy[nd];
			lazy[nd] = 0;
		}
		int mid = md;
		if( l <= mid){
			updater(st,mid,lc,l,r);
		}
		if( r > mid){
			updater(mid+1,en,rc,l,r);
		}
		
	}
}
 
long long query(int st, int en, int nd, int x){
	//cout<<st<<" "<<en<<endl;
	if(st == en){
		if(lazy[nd]){
			a[x] += lazy[nd];
			lazy[nd] = 0;
		}
		return a[x];
	}
	if(lazy[nd]){
		lazy[lc] += lazy[nd];
		lazy[rc] += lazy[nd];
		lazy[nd] = 0;
	}
	int mid = md;
	long long ret = 0;
	if(x <= mid){
		ret = query(st,mid,lc,x);
	}
	else{
		ret = query(mid+1,en,rc,x);
	}
	return ret;
}
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	build(0,n,0);
	while(q--){
		int x;
		cin>>x;
		if(x == 1){
			int l,r;
			cin>>l>>r>>val;
			updater(0,n,0,l,r);
		}else{
			int y;
			cin>>y;
			cout<<query(0,n,0,y)<<'\n';
		}
	}
	
	return 0;
}