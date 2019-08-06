#include<iostream>
using namespace std;typedef long long ll;ll t[10000000];int N,Q,v,q,l,z,u,a;
ll query(int r){ll s=0;for(;r>=0;r=(r&(r+1))-1)s+=t[r];return s;}
void update(int i,int m){for(;i<N;i=i|(i+1))t[i]+=m;}
int main(){cin>>N>>Q;for(a=0;a<N;++a){cin>>v;update(a,v);update(a+1,-v);}for(a=0;a<Q;++a){cin>>q;if(q==1){cin>>l>>z>>u;l--;z--;update(l,u);update(z+1,-u);}else{cin>>l;l--;cout<<query(l)<<'\n';}}}