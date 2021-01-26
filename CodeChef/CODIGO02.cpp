#include <bits/stdc++.h>
using namespace std;

int main() {
    int test, n, moves, a, b;
    cin >> test;
    while(test--){
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        moves = 0;
        a = 0;
        b = 0;
        for(int i=0; i<n; i++){
            b = a;
            for(int j=0; j<n; j++){
                if(arr[j]==(i+1)){
                    a = j;
                }
            }
            moves += abs(a-b);
        }
    cout << moves << "\n";
    }
    return 0;
}
