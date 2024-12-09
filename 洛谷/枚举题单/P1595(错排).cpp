#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    if(n == 1)
    {
        cout << 0;
        return 0;
    }
    if(n == 2)
    {
        cout << 1;
        return 0;
    }
    if(n == 3)
    {
        cout << 2;
        return 0;
    }
    vector<ll> a(30);
    a[1] = 0;
    a[2] = 1;
    a[3] = 2;
    for(int i = 4; i <= n; i++)
    {
        a[i] = (i-1)*(a[i-1] + a[i-2]);
    }
    cout << a[n];
    return 0;
}