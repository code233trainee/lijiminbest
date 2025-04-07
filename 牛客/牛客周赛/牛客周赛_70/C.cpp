#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    s = " " + s;
    int ans = 0;
    vector<int> nums;
    for(int i = 1; i <= n; i++)
    {
        if(s[i] == '1')
        {
            nums.push_back(i);
        }
    }
    ans = nums.size();
    cout << ans << endl;
    for(int i = 0; i < ans; i++)
    {
        cout << nums[i] << " " << nums[i] << endl;
    }
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