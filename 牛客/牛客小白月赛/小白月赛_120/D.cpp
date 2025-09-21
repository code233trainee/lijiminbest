#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    int pa = 0, pb = 0;
    int ans = 0;
    while(pa < n)
    {
        int val = a[pa];

        int ga = 0;
        while(pa + ga < n && a[pa + ga] == val) ga++;

        int gb = 0;
        while(pb + gb < m && b[pb + gb] == val) gb++;

        if(gb < ga)
        {
            cout << -1 << endl;
            return;
        }

        int per = (gb + ga - 1) / ga;
        int need = 0;
        if(per <= 1)
        {
            need = 0;
        }
        else
        {
            need = (int)ceil(log2((double)per));
        }

        ans = max(ans, need);

        pa = pa + ga;
        pb = pb + gb;
    }
    if(pb != m)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
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