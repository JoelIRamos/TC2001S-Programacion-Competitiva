// Funky Numbers
// Joel Ramos
// Context: A number is funky if it can be represented as: (k*(k+1))/2 where k is a positive integer.

#include <iostream>
using namespace std;

bool canBeMade(int n){
    for (int i = 1; i < n; i++){
        int k1 = (i * (i+1)) / 2;
        if (k1 > n){
            break;
        }
        for (int j = 1; j < n; j++){
            int k2 = (j * (j+1)) / 2;
            if (k1 + k2 == n){
                return true;
            }
            if (k1 + k2 > n){
                break;
            }
        }
    }
    return false;
}

int main(){
    // Read the number to test
    int n;
    cin >> n;
    // Print the result
    cout << (canBeMade(n) ? "YES" : "NO") << endl;
    return 0;
}
