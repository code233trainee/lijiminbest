#include <bits/stdc++.h>
using namespace std;
void solve()
{
    vector<int> a(6);
    cin >> a[1] >> a[2] >> a[4] >> a[5];
    int mx = 0;
    for(int i = -200; i <= 200; i++)
    {
        a[3] = i;
        int cnt = 0;
        for(int j = 1; j <= 3; j++)
        {
            if(a[j] + a[j+1] == a[j+2])
            {
                cnt++;
            }    
        }
        if(cnt > mx)
        {
            mx = cnt;
        }
    }
    cout << mx << "\n";
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