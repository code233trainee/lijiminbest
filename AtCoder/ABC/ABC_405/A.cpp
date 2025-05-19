#include <bits/stdc++.h>
using namespace std;
int main()
{
    int r, x;
    cin >> r >> x;
    if(x == 1)
    {
        if(r >= 1600 && r <= 2999)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    else if(x == 2)
    {
        if(r >= 1200 && r <= 2399)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}