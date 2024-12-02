#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        int ans = 0;
        while(1)
        {
            if(a==0 || b ==0)
            {
                break;
            }
            if(a > b)
            {
                a = a - b;
                ans++;
            }
            else
            {
                b = b - a;
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}