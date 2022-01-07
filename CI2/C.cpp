// Margarite and the best present
// Joel Ramos
#include <iostream>
#include <cmath>
using namespace std;

// Function that returns the sum of the sequence a[i] = i*(-1)^i from l to r
// Version 1
int solve(int l, int r) {
    int sum = 0;
    for (int i = l; i <= r; i++) {
        sum += i * pow(-1, i);
    }
    return sum;
}

// Function that returns the sum of the sequence a[i] = i*(-1)^i from l to r
// Version 2
int solve2(int l, int r) {
    int left, right;
    // If the left side is even
    if (l%2 == 0){
        left = (l/2);
    } // If its odd
    else{
        left = -(l+1)/2;
    }

    // Same as left
    if (r%2 == 0){
        right = (r/2);
    }
    else {
        right = -(r+1)/2;
    }

    // Return the difference
    return right - left;
}

int main(){
    // Read the number of queries
    int q, l, r;
    cin >> q;

    // Read the queries
    for (int i = 0; i < q; i++){
        // Read the left and right
        cin >> l >> r;
        
        // Print the result
        cout << solve2(l-1, r) << endl;
    }

    return 0;
}
