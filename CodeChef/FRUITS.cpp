#include <bits/stdc++.h>
using namespace std;

int main() {
	
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	int test,x,y,coin,dif,fac;
    cin >> test;

    for(int i=0; i<test ; i++){
        cin >> x >> y >> coin;
        dif = abs(x-y);
        fac = coin - dif;

        if(fac==0){
            cout << "0" << "\n";
        }else if(fac<0){
            cout << (-1*fac) << "\n";
        }else{
            if(dif%2==0){
                if(fac%2==0){ cout << "0" << "\n";}
                else{ cout << "1" << "\n";}         
            }else{
                if(fac%2==0){ cout << "0" << "\n";}
                else{ cout << "1" << "\n";}                           
            }
        }
    }

    return 0;

}
