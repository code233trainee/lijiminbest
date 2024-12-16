#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int a;
        cin >> a;
        double k = 0, x = 0, y = 0;
        while(a--)
        {
            cin >> k;
            x++;
            if( k == 1 )
            {
                y++;
            }
        }
        cout << std::fixed << std::setprecision(5) << (x-y)/x << "\n";
    }
    return 0;
}