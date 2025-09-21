#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> cnt(2e5+10);
    for(int i = 0; i < n*2; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans += min(cnt[i], 2);
    }
    cout << ans << endl;
    return 0;
}