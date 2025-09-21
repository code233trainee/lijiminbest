#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i != j)
            {
                double a;
                a = sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]));
                if(a == 1)
                {
                    ans++;
                }
            }
        }
    }
    cout << ans / 2 << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    //cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}