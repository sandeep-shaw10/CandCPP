/*
* Sandeep Shaw : MIT Licensed
* Time Complexity : O(n) [Single Testcase]
* Auxillary Space : O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t,n,x,y,min1,min2;
    
    cin >> t;
    
    for (int j = 0; j< t; j++) {
        
        cin >> n >> x >> y;
        if(x>y){
            min1 = y; //numeric_limits<int>::max();
            min2 = x; //numeric_limits<int>::max();
        }else{
            min1 = x; //numeric_limits<int>::max();
            min2 = y; //numeric_limits<int>::max();
        }
        
        
        for(int i=0; i<n-2; i++){
            cin >> x;
            if(x<min1){
                min2 = min1;
                min1 = x;
            }else if(x<min2){
                min2 = x;
            }else{
                //pass
            }
        }
        
        cout << (min1+min2) << endl;
        
        
    }
 
	// your code goes here
	return 0;
}
