#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    //想要一棵树有简单路径，那么这棵树就必须是退化为一个链
    //所以，每个节点的度必须小于等于2，度为1的两个节点，就是我们要找的路径的开始和终点
    vector<ll> a(n + 1);
    for(int i = 1; i < n; i++)
    {
        ll u, v;
        cin >> u >> v;
        a[u]++;
        a[v]++;
    }
    vector<ll> ans;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] > 2)
        {
            cout << "-1\n";
            return 0;
        }
        if(a[i] == 1)
        {
            ans.push_back(i);
        }
    }
    for(auto z : ans)
    {
        cout << z << " ";
    }
    return 0;
}
