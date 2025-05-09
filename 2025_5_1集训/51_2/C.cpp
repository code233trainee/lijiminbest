// https://codeforces.com/problemset/problem/1692/F
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> ma;
    vector<int> nums;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        int mod = a[i] % 10;
        if(ma[mod] < 3)
        {
            nums.push_back(mod);
            ma[mod]++;
        }
    }
    bool ok = false;
    n = nums.size();
    for(int i = 0; i < n && !ok; i++)
    {
        for(int j = i+1; j < n && !ok; j++)
        {
            for(int k = j+1; k < n; k++)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum % 10 == 3)
                {
                    ok = true;
                    break;
                }
            }
        }
    }
    cout << (ok ? "YES" : "NO") << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}