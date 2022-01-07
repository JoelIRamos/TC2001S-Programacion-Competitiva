#include <iostream>
using namespace std;

bool isPrime(int n){
    if (n <= 1){
        return false;
    }
    else if (n <= 3){
        return true;
    }
    else if (n % 2 == 0 || n % 3 == 0){
        return false;
    }
    else {
        for (int i = 5; i * i <= n; i = i + 6){
            if (n % i == 0 || n % (i + 2) == 0){
                return false;
            }
        }
        return true;
    }
}

int solvePrime(int a, int b) {
    bool flag = false;
    int cont = 0;
    if (a == b){
        return cont;
    }

    while (!flag){
        int i = 2;
        while (a < b){
            if (i > 5){
                return -1;
            }

            if (b%i == 0){
                b = b/i;
                cont++;
                // cout << "B: " << b << endl;
            }
            else {
                i++;
                if (i == 4) i++;
            }

            if (a == b){
                return cont;
            }
        }

        i = 2;
        while (b < a){
            if (i > 5){
                return -1;
            }
            if (a%i == 0){
                a = a/i;
                cont++;
                // cout << "a: " << a << endl;
            }
            else {
                i++;
                if (i == 4) i++;
            }

            if (a == b){
                return cont;
            }
        }
    }
    return cont;
}

int main(){
    int a, b;
    cin >> a >> b;

    cout << solvePrime(a, b) << endl;
    
    return 0;
}
