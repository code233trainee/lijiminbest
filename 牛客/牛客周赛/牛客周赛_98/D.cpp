#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> path;

void dfs(int rem, int last) {
    if (rem == 0) {
        
        for (int i = 0; i < (int)path.size(); i++) {
            if (i) cout << ' ';
            cout << path[i];
        }
        cout << "\n";
        return;
    }
   
    for (int v = 1; v <= rem; v++) {
        if (v == last) continue;    
        path.push_back(v);
        dfs(rem - v, v);
        path.pop_back();
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    dfs(n, -1);
    return 0;
}
