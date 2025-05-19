#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    // (a & b) + (a | b) = a+b
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i]*n;
    }
    cout << sum;
    return 0;
}