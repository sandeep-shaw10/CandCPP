#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b) {
    int temp;
    while(b > 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int test,val,result;
    cin >> test;
    
    for (int i = 0; i < test; i++) {
        cin >> val;
        int arr[val];
        
        for (int j = 0; j < val; j++) {
            cin >> arr[j];
        }
        
        result = arr[0];
        for(int j=0; j<val ; j++) {
            result = gcd(result, arr[j]);
            if(result==1){
                break;
            }
        }
        
        if(result==1){
            for(int j=0; j<val ; j++) {
                cout << arr[j] << " ";
            }
        }else{
            for(int j=0; j<val ; j++) {
                cout << (arr[j]/result) << " ";
            }           
        }
        cout<<"\n";
    }
 
	// your code goes here
	return 0;
}
