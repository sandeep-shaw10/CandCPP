#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int test, n, k, val;

    cin >> test;

    for(int i=0; i<test; i++){
        cin >> n >> k;
        val = 0;
        for(int j=1; j<=k; j++){
            val = max(val,n%j);
        }
        cout << val << "\n";
    }

	return 0;
}
