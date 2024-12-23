#include <bits/stdc++.h>
using namespace std;
int main()
{
    //210
    int total = 210;
    int k, n;
    cin >> k >> n;
    k--;
    bool ok = true;
    while(n--)
    {
        int ks;
        char c;
        cin >> ks >> c;
        total -= ks;
        if(total <= 0)
        {
            if(ok)
            {
                ok = false;
                cout << k+1 << "\n";
            }
            continue;
        }
        if(c == 'N' || c == 'P')
        {
            continue;
        }
        else
        {
            k = (k+1) % 8;
        }
    }
    return 0;
}