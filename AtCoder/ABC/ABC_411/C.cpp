#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, q;
    cin >> n >> q;
    vector<bool> a(n+2);
    int ans = 0;
    while(q--)
    {
        int x;
        cin >> x;
        if(a[x])
        {
            a[x] = false;
            if(a[x-1] && a[x+1])
            {
                ans++;
            }
            else if(a[x-1] || a[x+1])
            {
                cout << ans << endl;
                continue;
            }
            else
            {
                ans--;
            }
        }
        else
        {
            a[x] = true;
            if(a[x-1] && a[x+1])
            {
                ans--;
            }
            else if(a[x-1] || a[x+1])
            {
                cout << ans << endl;
                continue;
            }
            else
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}