// Funky Numbers
// Joel Ramos
// Context: A number is funky if it can be represented as: (k*(k+1))/2 where k is a positive integer.
#include <iostream>
#include <math.h>
using namespace std;

int closestfunky(int n) {
    int k = 0;
    while (n > 0) {
        n -= k;
        k++;
    }
    if (n == 0) {
        return k-1;
    }
    return k-2;
}

int funky(int n) {
    return (n * (n+1)) / 2;
}

bool canBeMade(int n){
    int half = n/2;
    int k = closestfunky(half);
    bool flag = false;
    while (flag){
        if (funky(k) * 2 == n) {
            return true;
        }
        if (funky(k) + funky(k-1) == n) {
            return true;
        }
        return false;
    }
}

int main(){
    // Read the number to test
    int n;
    cin >> n;

    // Print the result
    cout << (canBeMade(n) ? "YES" : "NO") << endl;
    
    return 0;
}
