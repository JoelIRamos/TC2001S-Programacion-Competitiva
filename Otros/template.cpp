#include <iostream>
#include <cmath>
using namespace std;

int main(){
    // Read the string
    string s;
    cin >> s;

    // Read the number of queries
    int q;
    cin >> q;

    // Read the queries
    for (int i = 0; i < q; i++) {
        // Read the query
        int l, r;
        cin >> l >> r;

        // Print the answer
        cout << s.substr(l - 1, r - l + 1) << endl;
    }
    
    system("pause");
    return 0;
}
