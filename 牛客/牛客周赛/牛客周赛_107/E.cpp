#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, a, k;
    cin >> n >> a >> k;
    if(k < (n + 1) / 2 + (a - n + 1) / 2 || k > (n + 1) / 2 + (a - n))
    {
        cout << -1 << endl;
        return;
    }
    if(n == 1)
    {
        cout << a << endl;
        return;
    }
    vector<int> vec(n, 1);
    k -= (n + 1) / 2;
    a -= n;
    vec[0] += k;
    vec[1] += a - k;
    for(int i = 0; i < n; i++)
    {
        cout << vec[i] << " ";
    }
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