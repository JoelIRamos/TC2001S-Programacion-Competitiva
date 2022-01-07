#include <iostream>
#include <map>
#define zero '0'
using namespace std;

int main(){
    int tests;
    string str;
    cin >> tests;

    for (int t = 0; t < tests; t++){
        map<char, int> icMap;
        cin >> str;
        int n = str.length();
        for (int i = 0; i < n; i++){
            icMap[str[i]]++;
        }

        int g = -1;
        int h = -1;
        int m = 0;

        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                bool flag = false;
                
                for (int k = 0; k < n; k++){
                    if (!flag && (str[k]-zero) == i){
                        m++;
                        flag = true;
                    } else if (flag && (str[k]-zero) == j){
                        m++;
                        flag = false;
                    }
                }

                if ((m%2) == 1){
                    m--;
                }

                g = max(g, m);
                m = 0;
            }
        }
        
        for (int i = 0; i < n; i++){
            h = max(h, icMap[str[i]]);
        }
        
        cout << min(n-h, n-g) << endl; 

    }
    return 0;
}
