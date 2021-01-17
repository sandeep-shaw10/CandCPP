#include <bits/stdc++.h>
using namespace std;

bool checkPrime(int a){
    int count = 0;
    for(int i=1; i<=a/2 ; i++){
        if(a%i==0){
            count++;
        }
    }
    if(count==1){
        return true;
    }else{
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	int test,x,y,sum,copy;
    bool notFound;
    cin >> test;

    for(int i=0; i<test ; i++){
        cin >> x >> y;
        sum = x+y;
        copy = sum;
        notFound = true;
        while(notFound){
            sum++;
            bool isPrime = checkPrime(sum);
            if(isPrime){
                notFound = false;
            }
        }
        cout << sum-copy << "\n";
    }
    return 0;
}
