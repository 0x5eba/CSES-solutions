#include <bits/stdc++.h> 
using namespace std; 
  
const int N = 100000;  
int n;
int tree[2*N]; 

void build(vector<int> &arr){  
    for (int i=0; i<n; i++)     
        tree[n+i] = arr[i]; 
    for (int i = n - 1; i > 0; --i)      
        tree[i] = tree[i<<1] + tree[i<<1 | 1];     
} 

void update(int p, int value){  
    tree[p+n] = value; 
    p += n; 
    
    for (; p > 1; p >>= 1) 
        tree[p>>1] = tree[p] + tree[p^1]; 
} 
  
int query(int l, int r){  
    int res = 0; 
      
    for (l += n, r += n; l < r; l >>= 1, r >>= 1){ 
        if (l&1)  
            res += tree[l++]; 
        if (r&1)  
            res += tree[--r]; 
    } 
    return res; 
} 