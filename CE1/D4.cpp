#include <iostream>
#include <vector>
using namespace std;

// Function to find if the string has an irreducible anagram
bool solve(string s){
    int n = s.length();

    // If only has one character, it has irreducible
    if (n == 1){
        return true;
    }
    // If the first and last char are the same, it has irreducible
    if (s[0] != s[n-1]){
        return true;
    }
    
    //  If it has more than 3 diferent characters, it has irreducible
    vector<char> v(3);
    v[0] = s[0];
    bool flag = false;
    for (int i = 1; i < n; i++){
        if (!flag){
            if (v[0] != s[i]){
                flag = true;
            }
        }
        else {
            if (s[i] != v[0] && s[i] != v[1]){
                return true;
            }
        }
    }
    
    // Else it doesn't have irreducible
    return false;
}

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
        cout << (solve(s.substr(l - 1, r - l + 1)) ? "Yes" : "No") << endl;
    }
    
    return 0;
}
