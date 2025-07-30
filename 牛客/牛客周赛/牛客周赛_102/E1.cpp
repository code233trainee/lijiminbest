#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int k = 2e5;
    vector<int> f(k + 1, 1e9), last(k + 1);
    f[0] = 0;
    for(int i = 1; i * (i + 1) / 2 <= k; i++)
    {
        int v = i * (i + 1) / 2;
        for(int j = v; j <= k; j++)
        {
            if(f[j-v] + i < f[j])
            {
                f[j] = f[j - v] + i + 1;
                last[j] = i;
            }
        }
    }
    int T = 1;
    cin >> T;
    while(T--)
    {
        int k;
        cin >> k;
        string ans;
        while(k > 0)
        {
            int w = last[k];
            int v = w * (w + 1) / 2;
            ans += string(w, '1');
            ans += '0';
            k -= v;
        }
        if(ans.back() == '0')
        {
            ans.pop_back();
        }

        cout << ans.size() << endl;
    }
}
int main()
{
    int t = 1;
    while(t--)
    {
        solve();
    }
    return 0;
}