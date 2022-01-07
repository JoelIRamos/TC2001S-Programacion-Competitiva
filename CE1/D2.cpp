#include <iostream>
#include <map>
using namespace std;

int main(){
    int t;
    string s;
    cin >> t;
    while(t--){
        int ans = 2;
        cin >> s;
        int n = s.length(); 
        for (char i = '0'; i <= '9'; i++){
            for (char j = '0'; j <= '9'; j++){
                int tm = 0;
                for (int k = 0; k < n; k++){
                    if(tm && s[k] == j){;
                        tm++;
                    }
                    else if (!tm && s[k] == i){
                        tm++;
                    }
                }
                if(i != j && tm){
                    tm--;
                }
                ans = max(ans, tm);
            }
        }
        cout << n-ans << endl; 
    }
    return 0;
}
