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
        int z = 0;
        for(int i = 0; i < 2*n; i++)
        {
            int a = 0;
            cin >> a;
            z += a;
        }
        cout << (z&1) << " " << min(z, 2*n-z) << endl;
    }
}