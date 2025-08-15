#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int k = n % 10;
    if(k == 0)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
    }
    return 0;
}