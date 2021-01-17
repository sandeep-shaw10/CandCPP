#include <bits/stdc++.h>
using namespace std;

int main() {
	
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test,a,b,c,d;
    cin >> test;
    for(int i=0; i<test ; i++){
        cin >> a >> b >> c >> d;
        if(a==b || a==c || a==d){
            if(a==b){
                if(c==d){cout << "YES" << "\n";}
                else{cout << "NO" << "\n";}
            } 
            else if(a==c){
                if(b==d){cout << "YES" << "\n";}
                else{cout << "NO" << "\n";}                
            }
            else{
                if(c==b){cout << "YES" << "\n";}
                else{cout << "NO" << "\n";}                
            }
        }else{
            cout << "NO" << "\n";
        }
    }

    return 0;

}
