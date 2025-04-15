#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    if(k == 1)
    {
        cout << "-1\n";
        return 0;
    }
    if(k > n)
    {
        cout << "0\n";
        return 0;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i != j)
            {
                if((a[i].first - a[i].second) == 0)
                {

                }
                else
                {
                    double k = (a[i].second - a[j].second) / (a[i].first - a[j].first);
                    for(int m = 0; m < n; m++)
                    {
                        
                    }
                }
            }
        }
    }
    return 0;
}