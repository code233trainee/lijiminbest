#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    s = '#' + s;
    int sum1 = 0;
    vector<int> suf1(n+2), pre0(n+1);
    for(int i = 1; i <= n; i++)
    {
        if(s[i] == '1')
        {
            sum1++;
            pre0[i] = pre0[i-1];
        }
        else
        {
            pre0[i] = pre0[i-1] + 1;
        }
    }
    for(int i = n; i >= 1; i--)
    {
        if(s[i] == '1')
        {
            suf1[i] = suf1[i+1] + 1;
        }
        else
        {
            suf1[i] = suf1[i+1];
        }
    }
    vector<int> v;
    if(sum1 >= (n+1)/2)
    {
        v.push_back(0);
    }
    for(int i = 1; i <= n; i++)
    {
        if(pre0[i] >= (i+1)/2 && suf1[i+1] >= (n - i + 1) / 2)
        {
            v.push_back(i);
        }
    }
    int ans = INT_MAX;
    int j = 0;
    for(int i = 0; i < v.size(); i++)
    {
        if(n % 2 == 0)
        {
            int k = abs(n / 2 - v[i]);
            if(k < ans)
            {
                ans = k;
                j = i;
            }
        }
        else
        {
            int k = min(abs(n/2 - v[i]), abs(n/2 + 1 - v[i]));
            if(k < ans)
            {
                ans = k;
                j = i;
            }
        }
    }
    cout << v[j] << endl;
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