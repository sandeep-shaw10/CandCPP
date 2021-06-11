# CandCPP

## Important: Competitive Programming 
##In CPP : `1 second = 10^7 instruction `

1) Fast Input/Output
```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int test;
    cin >> test;
  
    while(test--){
    //Your Code
    }
    
    return 0;
}

```

2) Seperate Function to Solve
```cpp
#include <bits/stdc++.h>
using namespace std;

void solve(){
	//Your Code
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int test;
    cin >> test;
  
    while(test--){
    	solve();
    }
    
    return 0;
}

```

3) Modulus 
```cpp
#define mod 1e9+7
```
[Know More about Modulo](https://discuss.codechef.com/t/output-modulo-10-9-7/16182)

4) STL : Vectors
```cpp
vector<int> g1;

/*
g1.push_back(i)
for (auto i = g1.cbegin(); i != g1.cend(); ++i){
	cout << *i << " ";
}
for (auto i = g1.crbegin(); i != g1.crend(); ++i){
	cout << *i << " ";
}
cout << "Size : " << g1.size();
cout << "\nCapacity : " << g1.capacity();
cout << "\nMax_Size : " << g1.max_size();
g1.resize(4);
g1.empty()
g1.shrink_to_fit();
g1.reverse();
g1.assign(5, 10); // [10,10,10,10,10]
*/
```
[VECTORS](https://en.cppreference.com/w/cpp/container/vector)


# PRE-COMPUTING PRIME NUMBERS
```cpp
const int limit = 1e7+5;
int pr[limit];

void seive(){
    fill(pr + 2, pr + limit, 1);
    for(int i = 2; i < limit; i++){
        if(pr[i]){
            for(int j = 2 * i; j < limit; j += i) {
                pr[j] = 0;
            }
        }
        if(i == 2){
            pr[i] = 0;
        };
        pr[i] += pr[i - 1];
    }
}
```

# GENERAL TREE DFS 
```cpp
#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vii;
typedef vector<int> vi;

void dfs(vii &edge, vi &subTree, vi &level, int cur = 1, int par = 0){

    cout << cur << "\n";
    subTree[cur] = 1;
    level[cur] = level[par] + 1;

    for(int neighb : edge[cur]){
        if(neighb == par) { continue; }

        dfs(edge, subTree, level, neighb, cur);

        subTree[cur] += subTree[neighb];
    }
}

void solve(){
    int n, k, u, v;
    cin >> n >> k;

    vii edge(n+1);
    vi subtree_size(n+1);
    vi level(n+1);

    for(int i = 0; i < n-1; i++){
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    cout << "Adjaceny List";
    for(const vi &it1 : edge){
        for(auto &it2 : it1){ cout << it2 << " "; }
        cout << endl;
    }
    cout << endl;

    level[0] = -1;

    cout << "Depth First Search" << endl;
    dfs(edge, subtree_size, level);
    cout << endl;

    cout << "Subtree Cout" << endl;
    for(int i=1; i<=n; i++){
        cout << i << "==>" << subtree_size[i] << endl;
    }
    cout << endl;

    cout << "Level Count" << endl;
    for(int i=1; i<=n; i++){
        cout << i << "==>" << level[i] << endl;
    }
    cout << endl << "==================================" << endl;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    int test;
    cin >> test;

    while(test--){
        solve();
    }
	
	return 0;
}

```


