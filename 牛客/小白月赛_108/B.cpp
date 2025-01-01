#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        ll a;
        cin >> a;
        vector<int> b;
        bool ok = false;
        if(a % 4 == 0)
        {
            cout << "YES\n";
            continue;
        }
        while(a)
        {
            b.push_back(a%10);
            a /= 10;
        }
        for(int i = 0; i < b.size(); i++)
        {
            for(int j = 0; j < b.size(); j++)
            {
                if(i != j)
                {
                    int temp = b[i] * 10 + b[j];
                    if(temp % 4 == 0)
                    {
                        cout << "YES\n";
                        ok = true;
                        break;
                    }
                }
            }
            if(ok)
            {
                break;
            }
        }
        if(ok)
        {
            continue;
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}