#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> cnt(111);
    int sum = 0;
    for(int i = n-1; i >= 0; i--)
    {
        for(int j = a[i] - 1; j >= 1; j--)
        {
            if(cnt[j] > 0)
            {
                sum += cnt[j];
            }
            sum %= 100;
        }
        cnt[a[i]]++;
    }
    cout << sum << endl;
}
int main()
{
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}