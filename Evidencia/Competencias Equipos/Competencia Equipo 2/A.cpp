// Fox Dividing Cheese
#include <iostream>
using namespace std;

/*
Two little greedy bears have found two pieces of cheese in the forest of weight a and b grams, correspondingly. The bears are so greedy that they are ready to fight for the larger piece. That's where the fox comes in and starts the dialog: "Little bears, wait a little, I want to make your pieces equal" "Come off it fox, how are you going to do that?", the curious bears asked. "It's easy", said the fox. "If the mass of a certain piece is divisible by two, then I can eat exactly a half of the piece. If the mass of a certain piece is divisible by three, then I can eat exactly two-thirds, and if the mass is divisible by five, then I can eat four-fifths. I'll eat a little here and there and make the pieces equal".

The little bears realize that the fox's proposal contains a catch. But at the same time they realize that they can not make the two pieces equal themselves. So they agreed to her proposal, but on one condition: the fox should make the pieces equal as quickly as possible. Find the minimum number of operations the fox needs to make pieces equal.
*/

// Function to know the minimun operations to make 2 pieces equal
// works similar to a minimum common divisor process
int solve(int a, int b) {
    // If the pieces are equal, return 0
    if (a == b) {
        return 0;
    }

    // Counters for each piece and one for the final result
    int contA[6] = {0, 0, 0, 0, 0, 0};
    int contB[6] = {0, 0, 0, 0, 0, 0};
    int contR[6] = {0, 0, 0, 0, 0, 0};

    // Flag that indicates if the division maxed out or not and if the number ended correctly
    bool flag = false;
    // MCD initiates with 2
    int i = 2;
    while (!flag) {
        // In this case, the maximum permited divisor is 5 
        if (i > 5) {
            // Break because the flag will show us that its a number that maxed out
            break;
        }
        
        // If the number is divisible by i, we add it to the counter
        if (a%i == 0) {
            a = a/i;
            contA[i]++;
        } // Else we increment i exept when i is 3, then we increment it by 2
        else {
            i++;
            if (i == 4) i++;
        }

        // If the number ended correctly (ended in 1)
        if (a == 1) {
            // Change the flag to true
            flag = true;
        }
    }

    // Flag that indicates the same
    int flag2 = false;
    i = 2;
    while (!flag2) {
        // In this case, the maximum permited divisor is 5
        if (i > 5) {
            // Break because the flag will show us that its a number that maxed out
            break;
        }
        
        // If the number is divisible by i, we add it to the counter
        if (b%i == 0) {
            b = b/i;
            contB[i]++;
        } // Else we increment i exept when i is 3, then we increment it by 2
        else {
            i++;
            if (i == 4) i++;
        }

        // If the number ended correctly (ended in 1)
        if (b == 1) {
            // Change the flag to true
            flag2 = true;
        }
    }

    // If any of the numbers maxed out
    if (!flag || !flag2) {
        // If the numbers are different, return -1
        if (a != b){
            return -1;
        }
    }

    // Store the absolute value of the difference between the two numbers
    for (int j = 2; j <= 5; j++) {
        contR[j] = contA[j] - contB[j];
        if (contR[j] < 0) {
            contR[j]*=-1;
        }
    }

    // Acumulate the values of the array
    int total = 0;
    for (int j = 2; j <= 5; j++) {
        total += contR[j];
    }
    // return the total
    return total;
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << solve(a, b) << endl;
    
    return 0;
}
