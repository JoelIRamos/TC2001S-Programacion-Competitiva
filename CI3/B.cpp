// Maximum Increase
// Joel Ramos
// Context: A Subarray is called increasing if each element is greater than the previous element.
#include <iostream>
#include <vector>
using namespace std;

// Function to find the maximum length of an increasing subarray
int maxIncrease(vector<int> array) {
    // If the vector is empty, return 0
    if (array.size() == 0) {
        return 0;
    }
    // Maximum length of an increasing subarray (starts at 1 given 1 element considered increasing)
    int maxLen = 1;
    // Current length of an increasing subarray (starts at 1 given 1 element considered increasing)
    int currLen = 1;
    // Previous element to compare with
    int prev = array[0];
    // For each element in the array (starts at 1 given the first element is the previous element)
    for (int i = 1; i < array.size(); i++) {
        if (array[i] > prev) {
            currLen++;
        }
        else {
            if (currLen > maxLen) {
                maxLen = currLen;
            }
            currLen = 1;
        }
        prev = array[i];
    }
    // Last comparison
    if (currLen > maxLen) {
        maxLen = currLen;
    }
    // Return the maximum length of an increasing subarray
    return maxLen;
}

int main(){
    // Read the length of the vector
    int l;
    cin >> l;

    // Read the vector
    vector<int> v(l);
    for(int i = 0; i < l; i++){
        cin >> v[i];
    }

    // Find the maximum lenght of an increasing subarray
    cout << maxIncrease(v) << endl;

    return 0;
}
