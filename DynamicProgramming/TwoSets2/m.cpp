#include<bits/stdc++.h> 
using namespace std; 
#define ll long long
  
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

// int partitioning(int n, ll sum) { 
//     int i, j; 

//     bool part[sum+1][n+1]; 
      
//     // initialize top row as true 
//     for (i = 0; i <= n; i++) 
//         part[0][i] = true; 
        
//     // initialize leftmost column, except part[0][0], as 0 
//     for (i = 1; i <= sum; i++) 
//         part[i][0] = false;      
       
//     // Fill the partition table in botton up manner  
//     for (i = 1; i <= sum; i++)   
//     { 
//         for (j = 1; j <= n; j++)   
//         { 
//             part[i][j] = part[i][j-1]; 
//             if (i >= j) 
//                 part[i][j] = part[i][j] || part[i - j][j-1]; 
//         }         
//     }     

//     // uncomment this part to print table  
//     for (i = 0; i <= sum; i++)   { 
//         for (j = 0; j <= n; j++)   
//             printf ("%4d", part[i][j]); 
//         printf("\n"); 
//     }
    
//     return part[sum][n]; 
// }    

int main() { 
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N = getint<int>();
    vector<int> v(N);
    
    // cout << partitioning(N, (N*(N+1)));
}