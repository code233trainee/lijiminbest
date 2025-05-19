#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1 == x2 && y1 == y2)
    {
        cout << "YES\n";
    }
    else if(x1 != x2 && y1 != y2)
    {
        if(abs(x1 - x2) == 1 && abs(y1 - y2) == 1)
        {
            if(y1 > y2)
            {
                if(x1>x2)
                {
                    cout << "YES\n";
                }
                else
                {
                    if(y1 == n - 1)
                    {
                        cout << "NO\n";
                    }
                    else
                    {
                        cout << "YES\n";
                    }
                }
            }
            else
            {
                if(x2>x1)
                {
                    cout << "YES\n";
                }
                else
                {
                    if(y2 == n - 1)
                    {
                        cout << "NO\n";
                    }
                    else
                    {
                        cout << "YES\n";
                    }
                }
            }
        }
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}