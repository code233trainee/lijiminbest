#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    string s;
    cin >> s;
    vector<bool> dp(9);
    dp[0] = true;
    for(char c : s)
    {
        vector<bool> new_dp(9);
        for(int x = 0; x < 9; x++)
        {
            if(dp[x])
            {
                int d = int(c - '0');
                while(d <= 9)
                {
                    new_dp[(x + d) % 9] = true;
                    if(d <= 1)
                    {
                        break;
                    }
                    d = d * d;
                }
            }
        }
        swap(dp, new_dp);
    }
    cout << (dp[0] ? "YES" : "NO") << '\n';


    // string s;
    // cin >> s;
    // long long sum = 0;
    // int sum2 = 0;
    // int sum3 = 0;
    // for(int i = 0; i < s.length(); i++)
    // {
    //     sum += s[i] - '0';
    //     if(s[i] == '2')
    //     {
    //         sum2++;
    //     }
    //     else if(s[i] == '3')
    //     {
    //         sum3++;
    //     }
    // }
    // int x = sum % 9;
    // if(x = 0){
    //     cout << "YES\n";
    // }
    // x = 9 - x;
    // if(x == 1 && (sum2 >= 5 || (sum2 >= 2 && sum3 >= 1))){
    //     cout << "YES\n";
    //     return;
    // }
    // if(x == 2 && sum2 > 0){
    //     cout << "YES\n";
    //     return;
    // }
    // if(x == 3 && (sum3 >= 2 || sum2 >= 6 || (sum3 >= 1 && sum2 >= 3))){
    //     cout << "YES\n";
    //     return;
    // }
    // if(x == 4 && sum2 >= 2) {
    //     cout << "YES\n";
    //     return;
    // }
    // if(x == 5 && (sum2 >= 7 || sum3 >= 1 && sum2 >= 4 || sum3 >= 2 && sum2 >= 1)) {
    //     cout << "YES\n";
    //     return;
    // }
    // if(x == 6 && (sum2 >= 3 || sum3 >= 1)) {
    //     cout << "YES\n";
    //     return;
    // }
    // if(x == 7 && (sum2 >= 8 || (sum2 >= 5 && sum3 >= 1) || (sum2 >= 2 && sum3 >= 2))) {
    //     cout << "YES\n";
    //     return;
    // }
    // if(x == 8 && (sum2 >= 4 || (sum3 >= 1 && sum2 >= 1))) {
    //     cout << "YES\n";
    //     return;
    // }
    // cout << "NO\n";
}
int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}

