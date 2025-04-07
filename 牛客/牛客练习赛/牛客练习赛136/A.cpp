#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    if(x * y >= z)
    {
        cout << z;
    }
    else
    {
        cout << x * y;
    }
    return 0;
}