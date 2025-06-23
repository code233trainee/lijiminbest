#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int a, b;
    cin >> a >> b;
    if(a == b)
    {
        cout << "Draw\n";
    }
    else
    {
        if(a == 0 && b == 1 || a == 1 && b == 2 || a == 2 && b == 0)
        {
            cout << "Hongwins\n";
        }
        else
        {
            cout << "chengwins\n";
        }
    }
    return 0;
}