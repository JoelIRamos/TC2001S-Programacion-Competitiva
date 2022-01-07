// Social Distance
#include <iostream>
#include <vector>
using namespace std;

// Funtion to find the maximum tables abailable
int solve(int n, int k, vector<int> tables) {
    int cont = 0;
    for (int i = 0; i < n; i++){
        // Si la mesa esta vacia
        if (!tables[i]){
            cont++;
        }
        else {
            cont = 0;
            i += k - 1;
        }
    }
    
}

int main(){
    int t, n, k;
    // Read number of test cases
    cin >> t;
    // For each test case
    for (int i = 0; i < t; i++){
        cin >> n >> k;
        // Read the vector of tables
        vector<int> tables(n);
        for (int j = 0; j < n; j++){
            cin >> tables[j];
        }

        // Solve the problem
        cout << solve(n, k, tables) << endl;
    }

    
    
    return 0;
}
