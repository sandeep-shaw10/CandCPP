#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int test, index, max;
    string s;
    int *alpha;


    cin >> test;
    while(test--){
        cin >> s;
        max = 0;

        alpha = (int*)malloc(26 * sizeof(int));

        if(alpha==NULL){
            cout << "crashed";
            exit(0);
        }else{

            //Setting all the alphabets to zero
            for(int i=0; i<26; i++){
                alpha[i] = 0;
            }

            //Setting the 
            for(int i=0; i<(int)(s.length()); i++){
                index = (int)s[i]-97;
                alpha[index] = 1 + alpha[index];
            }

            for(int i=0; i<26; i++){
                if(max<alpha[i]){
                    max = alpha[i];
                }
            }

            if((int)(s.length()-max) == max){
                cout << "YES\n";
            }else{
                cout << "NO\n";   
            }

            free(alpha);
        }

    }


	return 0;
}
