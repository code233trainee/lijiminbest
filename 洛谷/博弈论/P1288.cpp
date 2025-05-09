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
    for(int i = 1; i <= n; i++)
    {
        if(a[i] == 0)
        {
            if(i % 2 == 0)
            {
                cout << "YES\n";
                return 0;
            }
            break;
        }
    }
    for(int i = n; i >= 1; i--)
    {
        if(a[i] == 0)
        {
            if((n - i + 1) % 2 == 0)
            {
                cout << "YES\n";
                return 0;
            }
            break;
        }
    }
    cout << "NO\n";
    return 0;
}