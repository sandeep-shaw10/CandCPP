#include <bits/stdc++.h>
using namespace std;

int main() {
	
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	int test, n, k, l;
    string temp;
	cin>>test;

	while(test--){
        cin >> n >> k;
        string letter[n];
        for(int i=0; i<n; i++){
            cin >> letter[i];
        }
        set<string> str;
        while(k--){
            cin >> l;
            while(l--){
                cin >> temp;
                str.insert(temp);
            }
        }
        for(int i=0;i<n;i++){
            if(str.find(letter[i]) != str.end()){
                cout<<"YES ";
            }
            else{
                cout<<"NO ";
            }
        }
        cout<<"\n";
    }

	return 0;

}
