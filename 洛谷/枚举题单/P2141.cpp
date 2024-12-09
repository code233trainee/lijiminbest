#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    bool ok = false;
    for(int i = 0; i < n; i++)
    {
        int p = a[i];
        ok = false;
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < n; k++)
            {
                if(j != k)
                {
                    if(a[j] != p && a[k] != p)
                    {
                        if(a[j] + a[k] == p)
                        {
                            ans++;
                            ok = true;
                            break;
                        }
                    }
                }
            }
            if(ok)
            {
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}