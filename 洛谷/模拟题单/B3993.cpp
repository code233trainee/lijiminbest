#include <bits/stdc++.h>
using namespace std;

int main()
{
    int date[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int m, d;
    cin >> m >> d;
    if(m != 12)
    {
        if(d % date[m] == 0)
        {
            m += 1;
            d = 1;
            cout << m << " " << d << "\n";
            return 0;
        }
        cout << m << " " << d+1 << "\n";
    }
    else
    {
        if(d == 31)
        {
            cout << "1 1" << "\n";
            return 0;
        }
        cout << m << " " << d+1 << "\n";
    }
    return 0;
}