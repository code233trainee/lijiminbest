#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1);
    vector<bool> b(m+1, false);
    int ans = 0; 
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        b[a[i]] = true;
        bool ok = true;
        for(int j = 1; j <= m; j++)
        {
            if(b[j] == false)
            {
                ok = false;
                break;
            }
        }
        if(ok)
        {
            ans = n - i + 1;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}