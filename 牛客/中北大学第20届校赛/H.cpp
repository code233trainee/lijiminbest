#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int x, a, b;
    cin >> x >> a >> b;
    for(int i = 0; i * a <= x; i++)
    {
        int res = x - i * a;
        if(res % b == 0)
        {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}