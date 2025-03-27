#include <bits/stdc++.h>
using namespace std;
using i64 = long long int;
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    
    //题目要求所有子串中的最大平衡值等于k
    //abs(n - m) > k 整个字符串的平衡值会大于k的情况
    //max(n, m) < k 全为1或者全为0时的平衡值都会小于k的情况
    //这些情况不能满足题意
    if(abs(n - m) > k || max(n, m) < k)
    {
        cout << "-1\n";
        return;
    }

    int t = 0;
    if(n < m)
    {
        swap(n, m);
        t = 1;
    }
    string s;
    while(n > 0 || m > 0)
    {
        for(int i = 0; i < k && n; i++)
        {
            n--;
            s += '0' ^ t;
        }
        for(int i = 0; i < k && m; i++)
        {
            m--;
            s += '1' ^ t;
        }
    }
    cout << s << '\n';
}
int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}