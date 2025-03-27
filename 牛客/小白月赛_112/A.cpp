#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, w;
    cin >> a >> b >> w;
    if(w == a || w == b || w == a+b || w + a == b || w + b == a)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}