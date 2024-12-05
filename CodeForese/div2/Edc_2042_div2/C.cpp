#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b)
{
    return a > b;
}
void solve()
{
    int n, k;
    string s;
    cin >> n >> k >> s;

    vector<int> f(n);
    for(int i = n - 1; i >= 0; i--)
    {
        if(i < n - 1)
        {
            f[i] = f[i + 1];
        }
        if(s[i] == '1')
        {
            f[i]++;
        }
        else
        {
            f[i]--;
        }
    }
    f.erase(f.begin());
    sort(f.begin(), f.end(), cmp);
    long long sum = 0;
    for(int i = 1; i < n; i++)
    {
        sum += f[i - 1];
        if(sum >= k)
        {
            cout << i + 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}
