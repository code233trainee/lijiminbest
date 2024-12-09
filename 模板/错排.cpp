#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int mains()
{
    int n;
    cin >> n;
    vector<ll> a(100);
    a[1] = 0;
    a[2] = 1;
    a[3] = 2;
    for(int i = 4; i <= n; i++)
    {
        a[i] = (i - 1) * (a[i-1] + a[i-2]);
    }
    return 0;
}