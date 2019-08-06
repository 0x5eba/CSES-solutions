// #include<bits/stdc++.h>
// using namespace std;

// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")

// template<typename T> T getint() {
// 	T val=0;
// 	char c;
// 	bool neg=false;
// 	while((c=getchar()) && !(c>='0' && c<='9')) {
// 		neg|=c=='-';
// 	}
// 	do {
// 		val=(val*10)+c-'0';
// 	} while((c=getchar()) && (c>='0' && c<='9'));

// 	return val*(neg?-1:1);
// }

// #define INF 3e18 + 5
// typedef long long ll;

// struct FenwickTreeMin {
//     vector<ll> bit;
//     int n;

//     FenwickTreeMin(int n) {
//         this->n = n;
//         // bit.assign(n, INF);
//         bit.resize(n);
//     }

//     // FenwickTreeMin(vector<int> a) : FenwickTreeMin(a.size()) {
//     //     for (size_t i = 0; i < a.size(); i++)
//     //         update(i, i, a[i]);
//     // }

//     ll query(int r) {
//         ll ret = INF;
//         for (; r >= 0; r = (r & (r + 1)) - 1)
//             ret = min(ret, bit[r]);
//         return ret;
//     }

//     ll query(int l, int r) {
//         return query(r) - query(l - 1);
//     }

//     void update(int idx, ll val) {
//         for (; idx < n; idx = idx | (idx + 1))
//             bit[idx] = min(bit[idx], val);
//     }

//     void update(int l, int r, ll val) {
//         update(l, val);
//         update(r + 1, -val);
//     }

//     void print(){
//         for(auto a : bit)
//             cout << a << " ";
//         cout << endl;
//     }
// };


// int main() { 
//     ios::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);

//     int N = getint<int>(); 
//     int Q = getint<int>(); 

//     auto BITree = FenwickTreeMin(N);
//     for(int a = 0; a < N; ++a){
//         BITree.update(a, a, getint<ll>());
//     }

//     for(int a = 0; a < Q; ++a){
//         int l = getint<int>();
//         int r = getint<int>();
//         l--;
//         cout << BITree.query(l, r) << '\n';
//     }
// }