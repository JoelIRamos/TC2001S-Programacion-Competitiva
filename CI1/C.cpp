// Solution to Problem: Heaters
// Autor: Joel Ramos - A01245083
// Date: 26/10/2021
#include <iostream>
#include <vector>
using namespace std;

// Funtion that returns the minimun number of heaters needed to heat the house, or -1 if it is impossible to do it
int solve(vector<int> rooms, int r) {
    int n = rooms.size();
    vector<bool> warmRooms(n, false);
    int heaters = 0;
    int i = 0;
    while (i < n){
        int cont = 0;
        while (!rooms[i]){
            if (!warmRooms[i]){
                cont++;
            }
            i++;
            if (i >= n){
                return -1;
            }
        }
        if (r > cont){
            bool flag = false;
            for (int j = i; j < i-r; j--){
                if (j >= 0){
                    if (j != i){
                        if (rooms[j]) {
                            break;
                        }
                    }
                    if (!warmRooms[j]){
                        warmRooms[j] = true;
                        flag = true;
                    }
                }
            }
            for (int j = i; j < i+r; j++){
                if (j < n){
                    if (j != i){
                        if (rooms[j]) {
                            break;
                        }
                    }
                    if (!warmRooms[j]){
                        warmRooms[j] = true;
                        flag = true;
                    }
                }
            }
            if (flag){
                heaters++;;
            }
            i += r;
        }
        else{
            int warm = 0;
            for (int j = 0; j < n; j++){
                if (rooms[j]){
                    warm = r-1;
                } else {
                    if (warm > 0){
                        warm--;
                    } 
                    else {
                        return -1;
                    }
                }
            }
            i++;
        }
    }
    return heaters;
}


int main(){
    // n -> number of rooms in the house
    // r -> radius of the heaters
    int n, r;
    cin >> n >> r;
    vector<int> rooms(n);
    for (int i = 0; i < n; i++){
        cin >> rooms[i];
    }
    
    // Print the minimun number of heaters needed
    cout << solve(rooms, r) << endl;
    
    return 0;
}
