// Broken Keyboard
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

// Function to find wich keys aren't broken
string solve(string s){
    vector<bool> alphabet(26, false);
    string result = "";
    priority_queue<char> res;
    bool flag = false;

    // If there is only one character, return it
    if(s.length() == 1){
        return s;
    }

    int cont = 1;
    char letter = s[0];
    // For each letter in the string
    for(int i = 1; i < s.length(); i++){
        // If the letter stayed the same
        if (s[i] == letter){
            cont++;
        }
        else{ // If the letter is different
            if (cont % 2 != 0){
                // If it wasn't added to the bool vector before
                if (!alphabet[letter - 'a']){
                    // Add it to the bool vector
                    alphabet[letter - 'a'] = true;
                    // Add it to the result vector
                    res.push(letter);
                }
            }
            letter = s[i];
            cont = 1;
        }
    }
    // Last letter
    if (cont % 2 != 0){
        // If it wasn't added to the bool vector before
        if (!alphabet[letter - 'a']){
            // Add it to the bool vector
            alphabet[letter - 'a'] = true;
            // Add it to the result vector
            res.push(letter);
        }
    }

    
    // Convert the vector to string
    while (!res.empty()){
        result = res.top() + result;
        res.pop();
    }
    
    // Return the result
    return result;
}

int main(){
    // t -> test cases
    int t;
    cin >> t;

    // For each test case
    for (int i = 0; i < t; i++){
        string s;
        cin >> s;
        // Solve each case
        cout << solve(s) << endl;
    }
    return 0;
}
