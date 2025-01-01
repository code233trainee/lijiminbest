#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool cmp(int a, int b)
{
    return a > b;
}
void solve()
{
    ll n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if(n == 1)
    {
        cout << "-1\n";
        return;
    }
    sort(a.begin() + 1, a.end(), cmp);
    ll ans = 0;
    if(a[1] == 1)
    {
        //牌数最大的都为1了，肯定任意两张牌就可以获胜
        cout << "0\n";
    }
    else if(a[2] == 1)
    {
        //倒数第二大的牌为1，说明只有一种牌的数量不为1，只要预测到这个牌的数量减一，我们就可以确定剩下的牌未预测的牌都是相异的
        cout << a[1] - 1 << "\n";
    }
    else
    {
        //否则最坏情况我们需要预测出全部的最大数量的牌，然后剩下的未预测的牌就必定是相异的
        cout << a[1] << "\n";
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