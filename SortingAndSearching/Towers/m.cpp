#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	for(auto &x: v){
		cin >> x;
	}
	vector<int> active;
	for(auto x: v){
		auto p = upper_bound(active.begin(), active.end(), x);
		if(p == active.end()){
			active.push_back(x);
		}
		else{
			*p = x;
		}
	}
	cout << active.size();
	return 0;
}