#include <bits/stdc++.h>
using namespace std;

int distance(int x1,int x2,int y1,int y2){
    int d;
    d = ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    return d;
}

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int test, a1, a2, a3, b1, b2, b3, dist, count;

    cin >> test;

    for(int i=0; i<test; i++){
        cin >> dist >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;

        dist = dist*dist;
        count=0;

        if(distance(a1,a2,b1,b2)<=dist){
            count++;
        }

        if(distance(a1,a3,b1,b3)<=dist){
            count++;
        }

        if(distance(a2,a3,b2,b3)<=dist){
            count++;
        }

        if(count>=2){
            cout << "yes" << "\n";
        }else{
            cout << "no" << "\n";
        }
    }


	return 0;
}
