#include <iostream>
#include <string>
#include <math.h>
using namespace std;

#define ll long long

// Function to convert binary in string to decimal
ll toInt(string b){
    int a = 0;
    for(int i = 0; i < b.length(); i++){
        a += (b[i] - '0') * pow(2, b.length() - i - 1);
    }
    return a;
}

// Function to convert decimal to binary in string
string toBin(ll n){
    string b = "";
    while(n > 0){
        b = (n % 2 == 0 ? "0" : "1") + b;
        n /= 2;
    }
    return b;
}

// Function to find the number that '1' apears k in a string
bool countNum(string bin, int k){
    int count = 0;
    for (int i = 0; i < bin.length(); i++){
        if(bin[i] == '1'){
            count++;
        }
    }
    if(count == k){
            return true;
    }
    return false;
}

int solve(int k, string bin){
    ll num = toInt(bin);
    ll acum = 0;
    for (int i = 0; i <= num; i++){
        if (countNum(toBin(i), k)){
            acum++;
        }
    }
    return acum;
}

int main() {
    string s;
    cin >> s;

    int k;
    cin >> k;
    
    // TODO: TESTING
    // cout << s << " " << toInt(s) << endl;
    // cout << k << " " << toBin(k) << endl;
    cout << solve(k, s) << endl;
    
    system("pause");
    return 0;
}
