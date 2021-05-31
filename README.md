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


