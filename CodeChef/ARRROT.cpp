#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int size, query;
    long long sum = 0;
    long long mod = 1000000007;
    
    cin >> size;
    for(int i=0; i<size; i++){
        long long x;
        cin >> x;
        sum += x;
        sum = ((sum%mod)+mod)%mod;
    }
    
    cin>>query;
    for(int i=0; i<query; i++){
        long long y;
        cin >> y;
        sum += sum;
        sum = ((sum%mod)+mod)%mod;
        cout << sum << endl;
    }
    
    return 0;
}
