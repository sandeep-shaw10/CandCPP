#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test, k, n;
    cin >> test;

    while(test--){
        cin >> k >> n;
        int arr[n];

        for(int i=0; i<n; i++){
            cin >> arr[i];
        }

        int max, distance, temp;
        max = k + arr[0] - arr[n-1];
        distance =max;

        for(int i=0; i<n-1; i++){
            temp = arr[i+1]-arr[i];
            if(temp>max){
                max = temp;
            }
            distance += temp;
        }

        cout << distance-max << "\n";

    }

    return 0; 
}
