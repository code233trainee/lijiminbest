#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int mx = *max_element(a.begin(), a.end());
    while(m--)
    {
        char c;
        int l, r;
        cin >> c >> l >> r;
        if(c == '+')
        {
            if(mx >= l && mx <= r)
            {
                mx++;
            }
            cout << mx << " ";
        }
        else
        {
            if(mx >= l && mx <= r)
            {
                mx--;
            }
            cout << mx << " ";
        }
    }
    cout << endl;
}
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}