#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test;
    string val;
    cin >> test;

    while(test--){
        int binary[2] = {0,0};
        cin >> val;
        for(int i=0; i<(int)(val.length()); i++){
            if(val[i]=='1'){
                binary[1] = 1 + binary[1];
            }else{
                binary[0] = 1 + binary[0];
            }
        }
        if(binary[0]==1 || binary[1]==1){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }

	return 0;
}
