// Prime Matrix
// Joel Ramos
#include <iostream>

using namespace std;

#define MAX 500

// Basic Function to find if a number is prime
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

// Function to find the minimun number of steps to reach the prime matrix
int primeMatrix(int mat[MAX][MAX], int n, int m){
    // minimum -> minimum number of steps
    int minimum = INT_MAX;
    // c -> number of steps
    // v -> temporal value of cell
    int c, v;

    // Iterate the rows
    for (int i = 0; i < n; i++){
        // Re-start the counter
        c = 0;
        // Count the changes necesary to make the row full of prime numbers
        for (int j = 0; j < m; j++){
            v = mat[i][j];
            // Count the changes necesary to make the number prime
            while (!isPrime(v)){
                c++;
                v++;
            }
        }
        // Select the minimum number of changes
        minimum = min(minimum, c);
    }

    // Iterate the columns
    for (int i = 0; i < m; i++){
        // Re-start the counter
        c = 0;
        // Count the changes necesary to make the column full of prime numbers
        for (int j = 0; j < n; j++){
            v = mat[j][i];
            // Count the changes necesary to make the number prime
            while (!isPrime(v)){
                c++;
                v++;
            }
        }
        // Select the minimum number of changes
        minimum = min(minimum, c);    
    }

    // Return the number of the changes
    return minimum;
}

// Function to read the matrix
void readMatrix(int mat[MAX][MAX], int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }
}


int main(){
    int mat[MAX][MAX];
    
    // Read n and m (rows and columns)
    int n, m;
    cin >> n >> m;

    // Read the matrix
    readMatrix(mat, n, m);

    // Find the minimum number of steps
    cout << primeMatrix(mat, n, m) << endl;
    
    return 0;
}
