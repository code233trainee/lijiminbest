#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n+1);
    //记录每个点的度数
    for(int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u]++;
        a[v]++;
    }
    //找到最大的度数
    int m = 0;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] > m)
        {
            m = a[i];
        }
    }
    //找到非最大度点的,并且编号最小
    int root = -1;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] < m)
        {
            root = i;
            break;
        }
    }
    // 我们可以证明，对于一棵无根树，若我们选定某个节点作为根后，每个节点的孩子数目满足：
    // 对于根节点，它的孩子数就是它的原始度数（即和其它节点相连的边数）；
    // 对于非根节点，它的孩子数目则为它的度数减去 1（因为与父亲连接的那条边不算）。
    int k;
    if(root != -1)
    {
        k = m - 1;
    }
    else
    {
        root = 1;
        k = m;
    }
    cout << k << " " << root << "\n";
    return 0;
}