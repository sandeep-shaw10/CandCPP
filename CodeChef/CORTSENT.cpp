#include <bits/stdc++.h>
using namespace std;

// 0 => no language
// 1 => language1
// 2 => language2

int isLanguage(char letter){
    int x = (int)(letter);
    int lang = 0;

    if(x >= 97 && x <= 109){
        lang = 1;
    }

    if(x >= 78 && x <= 90){
        lang = 2;
    }

    return lang;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int test; 
	cin >> test;
	
	while(test--){
	    int k, check = 0;
        cin >> k;

        vector<string> collection;

        while(k--){
            string x;
            cin >> x;
            collection.push_back(x);
        }


        for (auto ir = collection.rbegin(); ir != collection.rend(); ++ir){

            string m = *ir;
            map<int, int> letter;
            int lang1 = 0, lang2 = 0;

            for(int i=0; i<m.length(); ++i){
                int x = isLanguage(m[i]);
                letter[x]++;
            }

            map<int, int>::iterator l1;
            map<int, int>::iterator l2;
            map<int, int>::iterator non;

            non = letter.find(0);
            if(non == letter.end()){
            }else{
                check = -1; break; 
            }


            l1 = letter.find(1);
            l2 = letter.find(2);
            if(l1 == letter.end()){
            }else{
                lang1 = l1->second; 
            }
            if(l2 == letter.end()){
            }else{
                lang2 = l2->second;
            }
            if(lang1 > 0 && lang2 > 0){ check = -1; break;}

        }

        if(check == -1){
            cout << "NO" << endl;
            check = 0;
        }else{
            cout << "YES" << endl;
        }

	}
	
	return 0;
}
