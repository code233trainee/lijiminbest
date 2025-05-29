#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1 > x2)
    {
        swap(x1, x2);
        swap(y1, y2);
    }
    if(x1 != x2)
    {
        if(y1 == y2+1 || (y1 == y2 - 1 && y2 + 1 < n))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    else
    {
        if(y1 == y2)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}