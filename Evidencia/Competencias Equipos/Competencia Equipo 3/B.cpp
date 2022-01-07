// Travelling Salesman and Special Numbers
#include <iostream>
#include <math.h>
using namespace std;

#define ll long long

// Function to convert binary in string to decimal
ll toInt(string b){
    ll a = 0;
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

ll countAux(string bin) {
    int count = 1;
    bool flag = false;
    while(!flag) {
        ll j = 0;
        for (int i = 0; i < bin.length(); i++) {
            if(bin[i] == '1'){
                j++;
            }
        }

        if(j == 1) {
            flag = true;
        }
        else {
            bin = toBin(j);
            count++;
        } 
    }
    return count;
}

ll solve(int k, string bin){
    ll num = toInt(bin);
    ll acum = 0;
    for (ll i = 1; i <= num; i++){
        if (countAux(toBin(i)) == k){
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
    
    cout << solve(k, s) << endl;

    return 0;
}
