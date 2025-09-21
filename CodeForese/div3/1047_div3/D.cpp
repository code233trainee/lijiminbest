#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> b(n), cnt(n+1);
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
        cnt[b[i]]++;
    }
    for(int i = 1; i <= n; i++)
    {
        if(cnt[i] && cnt[i] % i != 0)
        {
            cout << -1 << endl;
            return;
        }
    }
    int now = 1;
    vector<int> p(n+1, 0), a(n+1, 0);
    for(auto &z : b)
    {
        if(p[z] % z == 0)
        {
            a[z] = now++;
        }
        cout << a[z] << " ";
        p[z]++;
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}