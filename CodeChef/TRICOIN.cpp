// x = [n(n+1)]/2
// using Shridacharya Rule, n = floor{[sqrt(1+8x)-1]/2}
// Floor is used to find the maximum height of triangle formed

#include <bits/stdc++.h>
using namespace std;

int main() {
	
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test, x, count;
    float val;
    cin >> test;

    for(int i=0; i<test; i++){
        cin >> val;
        val = sqrt(8*val+1)-1;
        val = val/2;
        cout << floor(val) << "\n";
    }

    return 0;

}
