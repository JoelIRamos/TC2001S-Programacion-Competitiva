#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find if the string has an irreducible anagram
bool solve(string s){
    int n = s.length();
    // If only has one character, it is irreducible
    if (n == 1){
        return true;
    }
    // If the first and last char are the same, it is irreducible
    if (s[0] != s[n-1]){
        return true;
    }
    
    string str = s;
    sort(begin(str), end(str));
    auto last = unique(begin(str), end(str));
    str.erase(last, end(str));
    
    //  If it has more than 3 diferent characters, it is irreducible
    if (str.length() >= 3){
        return true;
    }
    
    // Else it is reducible
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
