#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, s;
    cin >> n >> s;
    int sum = 0;
    vector<int> a(n), cnt(3);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
        sum += a[i];
    }
    if(sum > s || s == sum + 1)
    {
        for(int i = 1; i <= cnt[1]; i++) cout << 1 << " ";
        for(int i = 1; i <= cnt[2]; i++) cout << 2 << " ";
        for(int i = 1; i <= cnt[0]; i++) cout << 0 << " ";
        cout << "\n";
    }
    else
    {
        cout << "-1\n";
    }
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}