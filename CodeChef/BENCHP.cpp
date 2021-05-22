#include <bits/stdc++.h> 
using namespace std; 

/*function for printing the elements in a list
void showlist(list <int> g)
{
    list <int> :: iterator it;
    for(it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}*/

int main() 
{ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test, freq, weight, rode;
    cin >> test;

    while(test--){
        cin >> freq >> weight >> rode;
        
        list <int> mass;
        int balanceFactor = 0;
        
        for(int i=0; i<freq; i++){
            int x;
            cin >> x;
            mass.push_back(x);
        }
        
        if(weight > rode){
            mass.sort();
            
            stack<int> torqueCheck;
            list<int>::iterator it = mass.begin();
            torqueCheck.push(*it);
            
            //Torque Check
            for(int i=1; i<freq; i++){
                advance(it, 1);
                if(torqueCheck.empty() || torqueCheck.top()!=*it){
                    torqueCheck.push(*it);
                }else{
                    torqueCheck.pop();
                    balanceFactor += *it;
                }
            }
            
           balanceFactor = 2*balanceFactor + rode;
           if(balanceFactor >= weight){
               cout << "YES" <<endl;
           }else{
               cout << "NO" << endl;
           }
        }else{
            cout << "YES" << endl;
        }
    }

    return 0; 
}


/*
#include <bits/stdc++.h>
using namespace std;

void showpair(map<int, int> &m)
{
    for(auto &pr : m){
        cout << pr.first << " " << pr.second << endl;
    }
    cout << '\n';
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int test = 1;
    unsigned long long int freq, weight, rode;
    cin>>test;
    
    while(test--)
    {
        cin >> freq >> weight >> rode;
        map<int, int> mass;
        unsigned long long int balanceFactor = rode;
        bool status = false;
            
        for(int i=0; i<freq; i++){
            int x;
            cin >> x;
            mass[x]++;
        }
        
        if(rode >= weight){
            cout << "YES" << endl;
        }else{
            //Touque Check
            for(auto &pr : mass){
                balanceFactor += pr.first * (pr.second/2) * 2;
                if(balanceFactor >= weight){
                    status = true;
                    break;
                }
            }
            
            if(status){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
        
    }
    return 0;
}*/
