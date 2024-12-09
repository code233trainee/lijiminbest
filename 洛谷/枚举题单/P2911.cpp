#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    map<int, int> ma;
    vector<int> va;
    for(int i = 1; i <= a; i++)
    {
        for(int j = 1; j <= b; j++)
        {
            for(int k = 1; k <= c; k++)
            {
                ma[i+j+k]++;
            }
        }
    }
    int mx = INT_MIN;
    for(auto z : ma)
    {
        if(z.second > mx)
        {
            mx = z.second;
        }
    }
    for(auto z : ma)
    {
        if(z.second == mx)
        {
            va.push_back(z.first);
        }
    }
    int ans = INT_MAX;
    for(int i = 0; i < va.size(); i++)
    {
        ans = min(ans, va[i]);
    }
    cout << ans << endl;
    return 0;
}