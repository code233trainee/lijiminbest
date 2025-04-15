#include <iostream>
#include <vector>
using namespace std;
int n, m;
bool dfs(int node, int parent, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, node, adj, visited))
                return true;
        } 
        else if (neighbor != parent && neighbor == m) {
            return true;
        }
    }
    return false;
}

int main(){
    
    cin >> n >> m;
    m--;
    vector<vector<int>> adj(n);
    // 输入边
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        a--;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }
    vector<bool> visited(n, false);
    bool hasCycle = dfs(m, -1, adj, visited);
    if (hasCycle)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
        
    return 0;
}
