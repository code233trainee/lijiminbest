#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main()
{
    int t;
    cin >> t;
    const ull max = 1e9 + 1;
    vector<ull> nums(max);
    for(int i = 1; i <= max; i++)
    {
        nums[i] += nums[i-1];
    }
    while(t--)
    {
        ull n, m, a, b;
        cin >> n >> m >> a >> b;
        ull ans = (a*nums[n-1] + b*(n-1))/m;
        
        cout << ans << "\n";
    }
}