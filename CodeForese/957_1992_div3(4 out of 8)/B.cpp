#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> vec(k);
    for(int i = 0; i < k; i++)
    {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    int ans = 0;
    for(int i = 0; i < k - 1; i++)
    {
        if(vec[i] != 0)
        {
            ans += ((vec[i] - 1) * 2) + 1;
        }
        else
        {
            ans++;
        }
    }
    cout << ans << "\n";
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