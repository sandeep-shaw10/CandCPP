#include <bits/stdc++.h>
using namespace std;

int main() {
	
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	int test,n;
    long long min;

	cin>>test;

	for(int i=0; i<test; i++){
	    cin>>n;
	    int arr[n];
	    for(int j=0;j<n;j++) {
            cin>>arr[j];
        }
	    min = *min_element(arr,arr+n);
	    
	    cout << min*(n-1) << "\n";
	}
	return 0;

}
