#include  <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    //输出不被g(i)影响的f(i)
    for(int i = n; i >= k; i--)
    {
        cout << i << " ";
    }
    //输出不影响结果的数字(这里的数字不小于m也不大于k,均为0)
    for(int i = m+1; i < k; i++)
    {
        cout << i << " ";
    }
    //输出g(i)
    for(int i = 1; i <= m ; i++)
    {
        cout << i << " ";
    }
    
    cout << endl;
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