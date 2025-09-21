#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    int maxlen = 0;
    vector<int> cnt(n+1), check(n+1), now;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        vector<int> nxt;
        //找因子
        for(int j = 1; j * j <= x; j++)
        {
            if(x % j == 0)
            {
                cnt[j]++;
                if(cnt[j] > maxlen && cnt[j] != i)
                {
                    maxlen = cnt[j];
                }
                if(cnt[j] == i)
                {
                    nxt.push_back(j);
                    check[j] = 1;
                }
                if(j*j != x)
                {
                    cnt[x/j]++;
                    if(cnt[x/j] > maxlen && cnt[x/j] != i)
                    {
                        maxlen = cnt[x/j];
                    }
                    if(cnt[x/j] == i)
                    {
                        nxt.push_back(x/j);
                        check[x/j] = 1;
                    }
                }
            }
        }
        //我们当前的数字可能不会与之前的所有数字产生相同的因数
        for(auto y : now)
        {
            if(!check[y])
            {
                maxlen = cnt[y];
            }
        }
        //回退一下
        for(auto y : nxt)
        {
            check[y] = 0;
        }
        now = nxt;
        cout << maxlen << " ";
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}