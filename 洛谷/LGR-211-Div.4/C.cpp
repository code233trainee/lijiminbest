#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll time = 0;
    ll n;
    cin >> n;
    ll cnt = 0;
    for(int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        if(b)
        {
            time += a;
            time += cnt * 20;
            cnt = 0;
        }
        else
        {
            cnt++;
        }
    }
    cout << time << "\n";
    return 0;
}