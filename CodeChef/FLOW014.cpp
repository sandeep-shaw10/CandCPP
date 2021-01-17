#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int test, hardness, tensile;
    float carbon;

    cin >> test;

    for(int i=0; i<test; i++){
        cin >> hardness >> carbon >> tensile;
        if(hardness>50 && carbon < 0.7 && tensile>5600){
            cout<<"10";
        }else if(hardness>50 && carbon < 0.7){
            cout<<"9";
        }else if(carbon < 0.7 && tensile>5600){
            cout<<"8";
        }else if(hardness>50 && tensile>5600){
            cout<<"7";
        }else if(hardness>50 || carbon < 0.7 || tensile>5600){
            cout<<"6";
        }else{
            cout<<"5";
        }
        cout<<"\n";
    }

	return 0;
}
