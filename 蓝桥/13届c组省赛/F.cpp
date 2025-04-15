// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// void solve(vector<ll> &a, ll x)
// {
//     ll L, R;
//     cin >> L >> R;
//     for(ll i = L; i <= R; i++)
//     {
//         for(ll j = L; j <= R; j++)
//         {
//             if((a[i] ^ a[j]) == x)
//             {
//                 cout << "yes" << endl;
//                 return;
//             }
//         }
//     }
//     cout << "no" << endl;
// }
// int main()
// {
//     ll n, m, x;
//     cin >> n >> m >> x;
//     vector<ll> a(n+1);  
//     for(int i = 1; i <= n; i++)
//     {
//         cin >> a[i];
//     }
//     while(m--)
//     {
//         solve(a, x);
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100010;
int dp[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    unordered_map<int, int> last;
    for(int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        dp[i] = max(dp[i-1], last[a^k]);
        last[a] = i;
    }
    while(m--)
    {
        int l, r;
        cin >> l >> r;
        cout << (dp[r] >= l ? "yes" : "no") << endl;
    }
    return 0;
}