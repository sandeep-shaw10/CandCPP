#include<bits/stdc++.h>
using namespace std;

vector<bool> prim(1000001, 0);
vector<int> sum(1000001, 0);

void seive(int n)
{
    bool pr[n + 1];
    memset(pr, true, sizeof(pr));
    
    //Prime number boolset
    for (int j = 2; j * j <= n; j++)
    {
        if (pr[j] == true)
        {
            for (int i = j * j; i <= n; i += j)
                pr[i] = false;
        }
    }
    
    //Tuple a+b+c
    for (int j = 2; j <= n; j++) {
        if (pr[j]) {
            prim[j] = 1;
            if (j - 2 >= 0 and prim[j - 2]) {
                sum[j] = sum[j - 1] + 1;;
            }
            else {
                sum[j] = sum[j - 1];
            }
        }
        else {
            sum[j] = sum[j - 1];
        }
    }
}

int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    seive(1000001);
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<sum[n]<<"\n";
    }
}
