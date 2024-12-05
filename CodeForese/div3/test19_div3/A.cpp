#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int ans = 0;
        for(int i = 1; i < n+1; i++)
        {
            int a;
            cin >> a;
            if(i%2)
            {
                ans += a; 
            }
            else
            {
                ans -= a;
            }
        }
        cout << ans << endl;
    }
}
