#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test, n, ans, current, index;
    cin >> test;

    while(test--){
        cin >> n;

        map<int, pair<int, int>>frog;

        int w[n];
        for(int i=0; i<n; i++){
            cin >> w[i];
        }

        int j[n];
        for(int i=0; i<n; i++){
            cin >> j[i];
        }

        for(int i=0; i<n; i++){
            frog[w[i]] = {j[i], i};
        }

        ans = 0;

        for(auto it = frog.begin(); it != frog.end(); it++){
            if(it==frog.begin()){
                current = (it->second).second;
            }else{
                index = (it->second).second;
                while(current>=index){
                    index += ((it->second).first);
                    ans++;
                }
                current = index;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
