#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    ll a = 0, b = 0;
    for(int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        a += x;
    }
    for(int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        b += x;
    }
    if(a % 2 == 1 && b % 2 == 1)
    {
        cout << "odd";
    }
    else
    {
        cout << "even";
    }
    return 0;
}