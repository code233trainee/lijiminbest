#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[4], b[4];
    for(int i = 0; i < 4; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < 4; i++)
    {
        cin >> b[i];
    }
    int ans = 0;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if((a[i] > a[j] && b[i] < b[j]) || (a[i] < a[j] && b[i] > b[j]))
            {
                ans++;
            }
        }
    }
    cout << ans/2 << "\n";
    return 0;
}