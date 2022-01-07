// Bear and Poker
#include <iostream>
#include <vector>
using namespace std;

void divide(int &n) {
    while(!(n%2)) n /= 2;
    while(!(n%3)) n /= 3;
}

bool solve(int n) {
    int first, num;
    cin >> first; divide(first);
    for(int i=1; i<n; i++) {
        cin >> num; divide(num);
        if(num != first) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    cout << (solve(n) ? "Yes" : "No") << endl;
    return 0;
}
