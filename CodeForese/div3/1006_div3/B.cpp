#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cntOn = 0, cntDown = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '-')
        {
            cntOn++;
        }
        else
        {
            cntDown++;
        }
    }
    if(cntDown < 1 || cntOn < 2)
    {
        cout << "0\n";
        return;
    }
    if(cntOn & 1)
    {
        //奇数
        ll a = cntOn / 2;
        ll b = cntOn - a;
        cout << cntDown * a * b << "\n";
    }
    else
    {
        //偶数
        ll a = cntOn / 2;
        cout << cntDown * a * a << "\n";
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}