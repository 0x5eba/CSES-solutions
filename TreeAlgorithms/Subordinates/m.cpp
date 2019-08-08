#include<bits/stdc++.h>
using namespace std; 
#define ll long long
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
  
struct node{
    vector<node*> childs;
    node* parent;
    int nChilds;
    int employNumber;
};

vector<int> nChilds(300000, 0);

void count_subnode(node* root, int s, int e) {
    nChilds[s] = 1;
    for(auto child : root->childs){
        if(child->employNumber == e) 
            continue;
        count_subnode(child, child->employNumber, s);
        nChilds[s] += nChilds[child->employNumber];
    }
}


bitset<300000> visited;

void dsf(node* root, int val, int currNode){
    visited.set(root->employNumber);

    if(root->employNumber == val){
        auto new_child = new node{};
        new_child->employNumber = currNode;
        root->childs.emplace_back(new_child);
        root->nChilds++;
        return;
    }

    for(auto child : root->childs){
        if(!visited.test(child->employNumber)){
            dsf(child, val, currNode);
        }
    }
}


void check(node* root){
    visited.set(root->employNumber);
    cout << root->employNumber << " have " << root->nChilds << endl;
    for(auto child : root->childs){
        cout << child->employNumber << " ";
    }
    cout << endl;

    for(auto child : root->childs){
        if(!visited.test(child->employNumber)){
            check(child);
        }
    }
}


int numberOfChildren(node* root, int x) { 
    int numChildren = 0;
    bool count = false;
    queue<node*> q; 
    q.push(root); 

    while (!q.empty()) { 
        auto p = q.front(); 
        q.pop(); 
        visited.set(p->employNumber);

        if(count){
            numChildren += p->nChilds;
        }

        if (p->employNumber == x && !count) { 
            // numChildren += p->nChilds; 
            count = true;
            queue<node*> empty;
            swap(q, empty);

            q.push(p);
            continue;
        } 

        for(auto child : p->childs){
            // if(!visited.test(child->employNumber))
            q.push(child);
        }
             
    } 

    return numChildren;
} 


int main() { 
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    auto root = new node{};
    root->parent = nullptr;
    root->employNumber = 1;

    int N = getint<int>();
    for(int a = 0; a < N-1; ++a){
        int val = getint<int>();
        int currNode = a+2;
        visited.reset();
        dsf(root, val, currNode);
    } 
    // visited.reset();
    // check(root);

    count_subnode(root, root->employNumber, 0);

    for(int a = 1; a <= N; ++a){
        cout << nChilds[a]-1 << " ";
    }
}