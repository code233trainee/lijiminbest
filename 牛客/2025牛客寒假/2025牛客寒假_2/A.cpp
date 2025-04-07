#include <bits/stdc++.h>
using namespace std;
int main()
{
    bool isok = true;
    for(int i = 1; i <= 7; i++)
    {
        int a;
        cin >> a;
        if(a == 1 || a == 2 || a == 3 || a == 5 || a == 6)
        {
            continue;
        }
        else
        {
            isok = false;
            break;
        }
    }
    if(isok)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}