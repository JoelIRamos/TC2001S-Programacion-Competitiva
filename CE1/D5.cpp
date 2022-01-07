#include <iostream>
#include <vector>
using namespace std; 

// Function to find if the string has an irreducible anagram
bool solve(string str, int l, int r){
    string s = str.substr(l - 1, r - l + 1);
    int n = s.length();

    // If it has more than 3 diferent characters, it has irreducible
    vector<char> v(3);
    v[0] = s[0];
    bool flag = false;
    bool flag2 = false;
    for (int i = 1; i < n; i++){
        if (flag){
            if (v[0] != s[i]){
                flag = true;
            }
        }
        else {
            if (s[i] != v[0] && s[i] != v[1]){
                flag2 = true;
            }
        }
    }

    // If only has one character, it has irreducible
    // If the first and last char are the same, it has irreducible
    if (l == r || str[l] != str[r] || flag2){
        return true;
    } // Else it doesn't have irreducible
    else { 
        return false;
    }
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
        cout << (solve(s, l, r) ? "Yes" : "No") << endl;
    }
    
    return 0;
}
