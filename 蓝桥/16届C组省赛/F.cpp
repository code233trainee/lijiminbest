#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        if((i + k) < n)
        {
            if(a[i] > a[i+k])
            {
                int temp = a[i] + a[i+k];
                if(temp % 2 == 0)
                {
                    a[i] = temp/2;
                    a[i+k] = temp/2;
                }
                else
                {
                    a[i] = temp/2;
                    a[i + k] = temp/2 + 1;
                }
            }
        }
    }
    int mn = 1e9;
    for(int i = 0; i < n; i++)
    {
        mn = min(mn, a[i]);
    }
    cout << mn;
    return 0;
}