// Solution to Problem: Heaters
// Autor: Joel Ramos - A01245083
// Date: 26/10/2021
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Funtion that returns the minimun number of heaters needed to heat the house, or -1 if it is impossible to do it
int solve(int n, int r){
    // h -> number of heaters
    // room -> a room in the house
    int h;
    int room;

    for (int i = 0; i < n; i++){
        cin >> room;
        if (room == 1){
            h++;
        }
    }

    // Formula to calculate the minimun number of heaters needed
    int minimun = ceil(n / (2 * r - 1));
    return (minimun > h || h == 0) ? -1 : minimun+1;
}

int main(){
    // n -> number of rooms in the house
    // r -> radius of the heaters
    int n, r;
    cin >> n >> r;
    
    // Print the minimun number of heaters needed
    cout << solve(n, r) << endl;
    
    return 0;
}
