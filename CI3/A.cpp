// Alex and Rhombus
// Joel Ramos
// Context: The number of square in a rombus is given by the formula: R(n) = 4n + R(n-1)
#include <iostream>
using namespace std;

#define ll long long

// Function that calculates the number of square in a rombus of order n
ll rombus(int n) {
    int acum = 1;
    for (int i = 1; i < n; i++){
        acum += 4 * i;
    }
    return acum;
}

int main(){
    int n;
    cin >> n;

    cout << rombus(n) << endl;
    
    // system("pause");
    return 0;
}