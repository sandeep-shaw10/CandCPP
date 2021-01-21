// CPP program To calculate The Value Of nCr 
#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test, num;
    unsigned long int val;
    cin >> test;

    while(test--){
        cin >> num;
        num = num-1;
        val = 1;
        while(num--){
            val = val * 2;
            val = val % 1000000007;
        }
        cout << val << "\n";
    }

    return 0; 
}
