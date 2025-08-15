#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt1 = 0, cnt0 = 0;
    set<int> n1, n0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i] == 1)
        {
            cnt1++;
            n1.insert(i);
        }
        else
        {
            cnt0++;
            n0.insert(i);
        }
    }
    if(n <= 2)
    {
        cout << "YES\n";
        return;
    }
    if(cnt1 == n || cnt0 == n)
    {
        cout << "YES\n";
    }
    else
    {
        int cnt = 0;
        if(a[0] == 0)
        {
            for(int i = 1; i < n; i++)
            {
                if(a[i] != a[i-1])
                {
                    cnt++;
                }
            }
            if(cnt > 2)
            {
                cout << "NO\n";
                return;
            }
        }
        else
        {
            for(int i = 1; i < n; i++)
            {
                if(a[i] != a[i-1])
                {
                    cnt++;
                }
            }
            if(cnt > 2)
            {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
    }
    
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}