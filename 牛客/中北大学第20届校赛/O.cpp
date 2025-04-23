#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < m; i++)
    {
        auto it = lower_bound(a.begin(), a.end(), b[i]);
        if(it == a.end())
        {
            cout << "-1 ";
        }
        else
        {
            cout << *it << " ";
        }
    }
    return 0;
}