#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> ans(n);
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    int x = -1;
    for(int i = 0; i < n; i++)
    {
        if(b[i] != -1)
        {
            x = a[i] + b[i];
        }
    }
    if(x == -1)
    {
        int minA = *(min_element(a.begin(), a.end()));
        int maxA = *(max_element(a.begin(), a.end()));
        int cnt = minA+k - maxA + 1;
        if(minA + k < maxA)
        {
            cout << "0\n";
        }
        else
        {
            cout << cnt << "\n";
        }
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            if(b[i] == -1)
            {
                if(a[i] > x)
                {
                    cout << "0\n";
                    return;
                }
                else if(k + a[i] < x)
                {
                    cout << "0\n";
                    return;
                }
            }
            else
            {
                if(b[i] + a[i] != x)
                {
                    cout << "0\n";
                    return;
                }
            }
        }
        cout << "1\n";
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