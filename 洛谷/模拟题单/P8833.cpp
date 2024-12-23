#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(22);
    for(int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        a[b]++;
    }
    for(int i = 0; i < m; i++)
    {
        int b;
        cin >> b;
        a[b]++;
    }
    int ans = 0;
    for(int i = 0; i <= 21; i++)
    {
        if(a[i] >= 2)
        {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}