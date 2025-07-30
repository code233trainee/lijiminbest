#include <bits/stdc++.h>
using namespace std;
int main()
{
    char c1, c2, c3;
    cin >> c1 >> c2 >> c3;
    if(c1 == c2 || c1 == c3 || c2 == c3)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}