// Good String 
#include <iostream>
#include <string>
#include<algorithm>
#include<vector>
using namespace std;

int solve(string s) {
    int len=s.length(), maxVal = 0, aux, flag;
    vector<int> nums(10, 0);

    for (int i=0; i<len; i++) nums[s[i]-'0']++;
    for (int i=0; i<10; i++) maxVal = max(maxVal, nums[i]);

    for (int i=0; i<10; i++){
        if (nums[i]*2 >= maxVal) {
            for (int j=0; j<10; j++){
                if (j!=i || nums[j]*2>=maxVal) {
                    aux = 0;
                    flag = 1;
                    for (int k=0; k<len; k++){
                        if (s[k]-'0'==i && flag) flag = 0;
                        else if (s[k]-'0'==j && !flag) aux++, flag = 1;
                    }
                    maxVal = max(maxVal, aux*2);
                }
            }
        }
    }
    return len-maxVal;
}

int main() {
    int t;
    string s;
    cin >> t;
    while (t--){
        cin >> s;
        cout << solve(s) << endl;
    }
}