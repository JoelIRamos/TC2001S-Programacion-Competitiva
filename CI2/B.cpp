// Petya and Origami
// Joel Ramos
#include <iostream>
using namespace std;

int origami[3] = {2, 5, 8};

// Funtion to find the the ceil of the division of two integers
int ceilDiv(int a, int b) {
    if (a % b == 0)
        return a / b;
    else
        return a / b + 1;
} 

// Function to find the minimum number of origami notebooks needed
int minNotebooks(int n, int k){
    int sheets = 0;
    for (int i = 0; i < 3; i++){
        sheets += ceilDiv(origami[i]*n, k);
    }
    return sheets;
}

int main(){
    // Read n and k
    // n -> number of friends
    // k -> number of origami sheets por notebook
    int n, k;
    cin >> n >> k;
    
    // Print the minimum number of notebooks needed
    cout << minNotebooks(n, k) << endl;

    return 0;
}
