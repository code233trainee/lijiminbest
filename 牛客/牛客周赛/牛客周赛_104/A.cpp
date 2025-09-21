#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ans = 0;
    for(int i = 1; i <= 4; i++)
    {
        int x;
        cin >> x;
        if(x == i)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}