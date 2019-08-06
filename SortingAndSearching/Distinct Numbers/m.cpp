#include <unordered_set>
#include <iostream>
using namespace std; 

int countDistinct(int arr[], int n) { 
    unordered_set<int> s; 

    int res = 0; 
    for (int i = 0; i < n; i++) { 
        if (s.find(arr[i]) == s.end()) { 
            s.insert(arr[i]); 
            res++; 
        } 
    } 
    return res; 
}
  
int main() 
{ 
    int N;
    cin >> N; 
    int *arr = new int[N];
    for(int a = 0; a < N; ++a)
        cin >> arr[a];
    cout << countDistinct(arr, N) << endl; 
    return 0; 
}