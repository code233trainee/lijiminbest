#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    if(k == n - 1)
    {
        cout << -1;
    }
    else
    {
        for(int i = 1; i <= k; i++)
        {
            cout << i << " ";
        }
        for(int i = k + 2; i <= n + 1; i++)
        {
            if(i == n + 1)
            {
                cout << k + 1 << " ";
            }
            else
            {
                cout << i << " ";
            }
        }
    }
    return 0;
}