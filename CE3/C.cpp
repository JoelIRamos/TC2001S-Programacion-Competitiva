#include <iostream>
#include <string>
using namespace std;

int solve(int n, int k, string& s){
    char past = s[0];
    int changes = 0;
    for (int i = 1; i < n; i++){
        if (past == s[i]){
            bool flag = false;
            for (int j = 0; j < k && !flag; j++){
                if (past != char('A' + j)){
                    if (i+1 < n){
                        if (char('A' + j) != s[i+1]){
                            s[i] = char('A' + j);
                            changes++;
                            flag = true;
                        }
                    } else {
                        s[i] = ('A' + j);
                        changes++;
                        flag = true;
                    }
                }
            }
        }
        past = s[i];
    }

    return changes;
}

// Caso especial del 2
int solve2(int n, string& s){
    string s1 = s;
    string s2 = s;
    int changes1 = 0;
    int changes2 = 0;

    bool flag = true;
    for (int i = 0; i < n; i++){
        if (flag){
            if (s1[i] != 'A'){
                s1[i] = 'A';
                changes1++;
            }
            flag = false;
        }
        else {
            if (s1[i] != 'B'){
                s1[i] = 'B';
                changes1++;
            }
            flag = true;
        }
        
    }

    flag = true;
    for (int i = 0; i < n; i++){
        if (flag){
            if (s2[i] != 'B'){
                s2[i] = 'B';
                changes2++;
            } else {
            } 
            flag = false;
        }
        else {
            if (s2[i] != 'A'){
                s2[i] = 'A';
                changes2++;
            } else {
            }
            flag = true;
        }
        
    }
    
    if (changes1 < changes2){
        s = s1;
        return changes1;
    }
    else {
        s = s2;
        return changes2;
    }
    
}

int main(){
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    if (k != 2){
        cout << solve(n, k, s) << endl;
        cout << s << endl;
    } else { // Caso especial del 2
        cout << solve2(n, s) << endl;
        cout << s << endl;
    }
    


    return 0;
}
