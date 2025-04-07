#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if(n <= 2)
    {
        cout << "-1\n";
        return 0;
    }
    int mx = 0;
    for(int i = 2; i <= n-1; i++)
    {
        if(a[i] > a[i-1] && a[i] > a[i+1])
        {
            int h = a[i] - (a[i-1] + a[i+1]) / 2;
            if(mx < h)
            {
                mx = h;
            }
        }
    }
    if(mx == 0)
    {
        cout << "-1";
        return 0;
    }
    cout << mx;
    return 0;
}