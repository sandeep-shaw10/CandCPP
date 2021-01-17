#include <bits/stdc++.h>
using namespace std;

int main() {
	
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	int test, min, max, len;
    string s1, s2;
    cin>>test;

    for(int i=0; i<test; i++){
        min=0;
        max=0;
        cin >> s1 >> s2;

        len = s1.length();

        for(int j=0; j<len ;j++){
            if(s1[j]!=s2[j] && s1[j]!='?' && s2[j]!='?'){
                min++;
                max++;
            }else if(s1[j]!=s2[j] || s1[j]=='?' ||s2[j]=='?'){
                max++;
            }
        }

        cout << min << " " << max << "\n";

    }
    return 0;

}
