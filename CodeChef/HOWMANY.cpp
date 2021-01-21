#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int num, val;
    cin >> num;
    if(num==0){
        cout << "1";
    }else{
        val = (int)(log10(num)+1);
        if(val==1){
            cout << "1";
        }else if(val==2){
            cout << "2";
        }else if(val==3){
            cout << "3";
        }else{
            cout << "More than 3 digits";
        }
    }

	return 0;
}
