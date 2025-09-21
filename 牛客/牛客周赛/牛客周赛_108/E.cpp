#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<int>> dp(110, vector<int>(20010, 0));
// bool squre(int x)
// {
//     int y = sqrt(x);
//     return y * y == x;
// }
// bool check(int x)
// {
//     if(!squre(x))
//     {
//         return false;
//     }
//     int sum = 0;
//     while(x)
//     {
//         sum += x % 10;
//         x /= 10;
//     }
//     return squre(sum);
// }
void init()
{
    vector<int> need = {1, 4, 9, 36, 81, 100, 121, 144, 169, 196, 225, 324, 400, 441, 484, 529, 900, 961, 1521, 1681, 2025, 2304, 2601, 3364, 3481, 3600, 4489, 4624, 5776, 5929, 7225, 7396, 8100, 8836, 9025, 10000, 10201, 10404, 10609, 10816, 11025, 12100, 12321, 12544, 12769, 14400, 14641, 14884, 16900, 17161, 19321, 19600};
    // for(int i = 1; i <= 100; i++)
    // {
    //     int j = i * i;
    //     if(check(j))
    //     {
    //         need.push_back(j);
    //     }
    // }

    dp[0][0] = 1;
    //dp数组含义：用i个元素能否凑出j
    for(int i = 0; i <= 100; i++)
    {
        for(int j = 0; j <= 20000; j++)
        {
            if(dp[i][j])
            {
                for(auto v : need)
                {
                    if(j + v <= 20000)
                    {
                        dp[i+1][j+v] = 1;
                    }
                }
            }
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sum += x;
    }
    cout << (dp[n][sum] ? n : n - 1) << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    init();
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}