#include <bits/stdc++.h>
using namespace std;

int main() {
	
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, m, count;
    count = 0;
    string command;
    cin >> n >> k;

    int a[n]={0};

    for(int i=0; i<k; i++){
        cin >> command;
        if(command == "CLICK"){
            cin >> m;
            if(a[m-1]==0){
                a[m-1] = 1;
                count++;
            }else{
                a[m-1] = 0;
                count--;
            }
        }else{
            count = 0;
            for(int j=0;j<n;j++){
                a[j] = 0;
            }
        }

        cout << count << "\n";

    }

    return 0;

}
