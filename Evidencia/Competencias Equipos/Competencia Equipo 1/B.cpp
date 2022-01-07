// Social Distance 
#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int solve(int n, int k, string s) {
    int res=0, i=0, j, len;
    
    while(i < n) {
        j = i+1;

        while(j<n && s[j]!='1') j++;
        len = j-i;
        if(s[i]=='1') len -= (k+1); // izquierda
        if(j<n && s[j]=='1') len -= k; // derecha

        if(len>0) res += ceil((len*1.0)/(k+1));
        
        i=j;
    }

    return res;
}

int main() {
    int t, n, k;
    string s;
    cin >> t;
    while(t--) {
        cin >> n >> k >> s;
        cout << solve(n, k, s) << endl;
    }
}