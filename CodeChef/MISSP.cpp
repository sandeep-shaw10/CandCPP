#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int test, n;
    int *ptr;
    cin >> test;

    while(test--){
        cin >> n;

        //Dynamic Memory Allocation
        ptr = (int*)malloc(n * sizeof(int));

        //Checking the Allocation
        if(ptr==NULL){
            cout << "Crashed";
            exit(0);
        }else{
            //Successfull Allocation
            for (int i = 0; i < n; ++i) { 
                cin >> ptr[i]; 
            }

            //Sorting the path
            sort(ptr,ptr+n);

            //Checking for pairs
            for (int i = 0; i < n-1; ++i) { 
                if(ptr[i]==ptr[i+1]){
                    ptr[i] = -1;
                    ptr[i+1] = -1;
                    i++;
                }
            }            

            //pRINTING THE aRRAY
            for (int i = 0; i < n; ++i) {
                if(ptr[i] != -1)
                {
                    cout << ptr[i] << "\n";
                }
            }

            //Releasing the Memory
            free(ptr);
        }

    }
    
	return 0;
}
