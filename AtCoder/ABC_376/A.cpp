#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, c;
    cin >> n >> c;
    vector<int> tt(n + 1);
    int ans = 0;
    int time = 0;
    int lastTime = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> tt[i];
        if(i == 1)
        {
            ans++;
            time += tt[i];
            lastTime = time;
            continue;
        }
        time += tt[i] - tt[i-1];
        if(time - lastTime  >= c)
        {
            ans++;
            lastTime = time;
        }
    }
    cout << ans << endl;
}
int main()
{
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
}