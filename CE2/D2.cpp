// Linova and Kingdom 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 2e5+5;

struct ciudad {
    int sub = 0;
    int pasos = 0;
    vector<int> sa;
}

a[N];
bool cmp(ciudad a, ciudad b){
    return a.pasos-a.sub > b.pasos-b.sub;
}

vector<bool> vis(N);

int dfs(int x) {
    vis[x] = 1;
    for (int i = 0; i < a[x].sa.size(); i++){
        if (!vis[a[x].sa[i]]) {
            a[x].sub++;
            a[a[x].sa[i]].pasos = a[x].pasos + 1;
            a[x].sub+=dfs(a[x].sa[i]);
        }
    }
    return a[x].sub;
}

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n - 1; i++) {
        int s, t;
        cin >> s >> t;
        a[s].sa.push_back(t);
        a[t].sa.push_back(s);
    }

    dfs(1);

    sort(a + 1, a + n + 1, cmp);
    long long res = 0;      
    for(int i=1;i<=k;i++){
        res += a[i].pasos-a[i].sub;
    }
    cout << res << endl;
    return 0;
}