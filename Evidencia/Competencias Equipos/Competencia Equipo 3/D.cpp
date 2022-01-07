// As Simple as One and Two
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void solve(string s) {
    vector<int> r;
    int i, len=s.size();

    for (int i=0; i<len-1; i++) {
        if (s[i]=='o' && s[i+1]=='n' && s[i+2]=='e') {
            r.push_back(i+2);
            i += 2;
        } else if (s[i]=='t' && s[i+1]=='w' && s[i+2]=='o') {
            if (s[i+3]=='n' && s[i+4]=='e') {
                r.push_back(i+3);
                i += 4;
            } else {
                r.push_back(i+2);
                i += 2;
            }
        } 
    }	

    cout << r.size() << endl;
    if(r.size()!=0) {
        for(int i=0; i<r.size(); i++) {
            cout << r[i];
            if(i<r.size()-1) cout << " ";
        }
        cout << endl;
    }
}

int main() {
    int t;
    string s;
    cin >> t;
    while(t--) {
        cin >> s;
        solve(s);
    }
    return 0;
}