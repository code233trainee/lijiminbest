#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    int ans = 0;
    int cnt = 1;
    for(int i = 1; i < n; i++)
    {
        if(vec[i] == vec[i-1])
        {
            cnt++;
        }
        else
        {
            ans = max(ans, cnt);
            cnt = 1;
        }
    }
    ans = max(ans, cnt);
    cout << n - ans << endl;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}