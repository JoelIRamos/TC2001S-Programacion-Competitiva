#include <iostream>
#include <cstring>
#define zero '0'
using namespace std;


int main() {
    int t, l, cnt[10], mx;
    string str;

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        cin >> str;
        for (int i = 0; i < 10; i++){
            cnt[i] = 0;
        }
        l = str.length();
        for (int i = 0; i < l; i++){
            cnt[str[i]-zero]++;
        }
        mx = 0;
        for (int i = 0; i < 10; i++){
            mx = max(mx, cnt[i]);
        }
        for (int i = 0; i < 10; i++){
            if (cnt[i]*2 < mx) continue;
            for (int j = 0; j < 10; j++){
                if (j == i) continue;
                if (cnt[j]*2 < mx) continue;
                bool flag = true;
                int cnt = 0;
                for (int k = 0; k < l; k++){
                    if (flag && str[k]-'0' == i){
                        flag = false;
                    } else if (!flag && str[k]-'0' == j){
                        cnt++;
                        flag = true;
                    }
                }
                mx = max(mx, cnt*2);
            }
        }
        cout << l-mx << "\n";
    }
}