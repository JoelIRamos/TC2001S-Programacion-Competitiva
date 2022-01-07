// The Way to Home
// Joel Ramos
#include <iostream>
#include <string>
using namespace std;

int solve2(string axis, int d, int n) {
    int jumps = 0;
    int cont = 0;
    for (int i = 0; i < n-1; i++) { 
        int pos = 0; 
        for (int j = 1; j <= d; j++) { //TODO caso que sale del rango
            if (axis[i+j] == '1') {
                if (j > pos) { 
                    pos = j;
                }
            }
        }
        if (pos == 0) {
            return -1;
        }
        
        jumps++;
        i += pos-1;
    }
    return jumps;
}

int main(){
    int n, d;
    cin >> n >> d;

    string s;
    cin >> s;

    cout << solve2(s, d, n) << endl;
    return 0;
}