#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, x;
    cin >> n >> x;
    int cnt = 0;
    int temp = x;
    int bits = 0;
    vector<int> a1;
    while(temp)
    {
        cnt += temp & 1;
        bits++;
        if(temp&1)
        {
            a1.push_back(bits);
        }
        temp >>= 1;
    }
    if(x == 0)
    {
        if(n % 2 == 0)
        {
            cout << n * 1 << "\n";
        }
        else
        {
            if(n > 1)
            {
                cout << (n-1) * 1 + 2*2 << endl;
            }
            else
            {
                cout << "-1\n";
            }
        }
    }
    else
    {
        int k = a1.size();
        if(k < n)
        {
            if((n - k) % 2 == 0)
            {
                cout << x + (n - k) << "\n";
            }
            else
            {
                if(a1[0] == 1 && a1.size() == 1)
                {
                    cout << x + (n - k - 1) + 4 << endl;
                }
                else
                {
                    cout << x + (n - k - 1) + 2 << endl;
                }
            }
        }
        else
        {
            cout << x << endl;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}