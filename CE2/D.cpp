// Linova and Kingdom
#include <iostream>
#include <vector>
using namespace std;

#define matrix vector< vector<bool> > 

int main(){
    // Read the number of cities and industry cities
    int n, k;
    cin >> n >> k;

    vector<bool> iVCities(n+1, false);
    matrix iMCities(n+1, iVCities);

    // Read the cities
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        iMCities[u][v] = true;
        iMCities[v][u] = true;
    }
    
    system("pause");
    return 0;
}
