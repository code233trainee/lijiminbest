#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a, p;
        cin >> a >> p;
        if(p < 16)
        {
            a -= 10;
        }
        if(p > 20)
        {
            a -= p - 20;
        }
        cout << max(a, 0) << "\n";
    }
    return 0;
}