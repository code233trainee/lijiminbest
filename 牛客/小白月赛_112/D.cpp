#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> degree(n + 1, 0);
    
    // 读入 n-1 条边，并统计每个节点的度数
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        degree[u]++;
        degree[v]++;
    }
    
    // 求所有节点的最大度数 M
    int M = 0;
    for (int i = 1; i <= n; i++){
        M = max(M, degree[i]);
    }
    
    int root = -1;
    // 遍历所有节点，找出编号最小的度数小于 M 的节点
    for (int i = 1; i <= n; i++){
        if (degree[i] < M) {
            root = i;
            break;
        }
    }
    
    int k;
    if(root != -1){
        // 如果存在度数小于 M 的节点，k = M-1
        k = M - 1;
    } else {
        // 否则，所有节点度数均为 M，k = M，取最小编号节点（1）
        k = M;
        root = 1;
    }
    
    cout << k << " " << root << "\n";
    return 0;
}
