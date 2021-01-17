#include <bits/stdc++.h>
using namespace std;

#define ROUND(x) fixed << setprecision(x);

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int test;
    float salary;

    cin >> test;

    for(int i=0; i<test; i++){
        cin >> salary;
        if(salary>=1500){
            salary = salary + 500 + 0.98*salary;
        }else{
            salary = salary + 0.1*salary + 0.9*salary;
        }
        cout << ROUND(2);
        cout << salary << "\n";
    }

	return 0;
}
