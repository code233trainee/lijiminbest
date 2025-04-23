#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool isPrime(long long n) {
    if (n < 2) return false; // 1 和 0 不是质数
    // 从 2 到 sqrt(n) 遍历
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false; // 找到因子则不是质数
    }
    return true; // 没有找到因子，则是质数
}
vector<int> generateSol(int n, int p)
{
    vector<int> ans;
    ans.push_back(p);
    for(int i = 1; i <= n; i++)
    {
        if(p - i > 0)
        {
            ans.push_back(p - i);
        }
        if(p + i <= n)
        {
            ans.push_back(p + i);
        }
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> ans;
    for(int x = 0; ; x++)
    {
        if(isPrime(n / 2 - x))
        {
            ans = generateSol(n, n / 2 - x);
            break;
        }
        if(isPrime(n / 2 + x))
        {
            ans = generateSol(n, n / 2 + x);
            break;
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout << ans[i] << " \n"[i == n - 1];
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
    return 0;
}