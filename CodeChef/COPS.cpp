#include <bits/stdc++.h>
using namespace std;

int main() {
	
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test, m, x, y;
    int val, upper, lower, count;
    cin >> test;

    for(int i=0; i<test; i++){
    
        int arr[100] = {0};
        count = 0;

        cin >> m >> x >> y;
        for(int j=0; j<m ; j++){
            cin >> val;
            upper = val + x*y - 1;
            lower = val - x*y - 1;

            if(lower<0){
                lower = 0;
            }

            if(upper>99){
                upper = 99;
            }

            for(int k=lower; k<=upper; k++){
                arr[k] = 1;
            }           

        }

        for(int k=0; k<=99; k++){
                if(arr[k]==0){
                    count++;
                }
        }

        cout << count << "\n";
    }

    return 0;

}
