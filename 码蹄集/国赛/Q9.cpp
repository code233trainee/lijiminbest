#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    while(m--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        l--;
        r--;
        for(int i = l; i <= r; i++)
        {
            a[i] = x;
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}