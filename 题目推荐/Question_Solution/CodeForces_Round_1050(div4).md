# CodeForces Round 1050(div4)

竞赛地址：https://codeforces.com/contest/2148

### A.Sublime Sequence

相邻的两个元素会抵消，所以答案要么是x，要么是0。

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int x, n;
    cin >> x >> n;
    if(n % 2)
    {
        cout << x << endl;
    }
    else
    {
        cout << 0 << endl;
    }
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
```

### B.Lasers

其实注意到，我们的初始位置一定是左下角，终点位置(给定的激光的位置不会超过(x,y))一定是右上角，所以无论如何我们都会穿越所有的激光线。

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    cout << n + m << endl;
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
```

### C.Pacer

注意到，我们想在能够达到要求的基础上尽可能的使得分数增加。

一共有两种情况，

1. 下次要求的边与当前是同一边。
2. 下次要求的边与当前不同。

第一种情况，当边相同，当距离为偶数时等分为距离S，为奇数时则为S-1。

第二种情况，当边不同，当距离为奇数时得分为S，为偶数时则为S-1.

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1), b(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
    }
    int now = 0;
    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ll len = a[i] - a[i-1];
        int need = (now != b[i]);
        ll add = ( (len % 2 == need) ? len : (len - 1) );
        ans += add;
        now = b[i];
    }   

    ans += m - a[n];
    
    cout << ans << endl;
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
```

### D.Destruction of the Dandelion Fields

贪心。

只有当有田地的蒲公英数量是奇数时，我们才有收获(需要开启收割机)。

然后我们可以收割所有的蒲公英数量为偶数的田地。

对于奇数数量的田地，我们最多可以收割$\left \lceil \frac{sum_{odd}}{2}  \right \rceil$块田地。

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> odd, even;
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(x % 2)
        {
            odd.push_back(x);
        }
        else
        {
            even.push_back(x);
            ans += x;
        }
    }
    sort(odd.begin(), odd.end(), greater<int>());
    // sort(even.begin(), even.end(), greater<int>());
    if(odd.size() == 0)
    {
        cout << 0 << endl;
        return;
    }
    int len = (odd.size() + 1) / 2;
    for(int i = 0; i < len; i++)
    {
        ans += odd[i];
    }
    cout << ans << endl;
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
```

### E.Split

我们想要一个子数组合法，我们需要保证选择的子数组中的每个元素，在这个子数组之外的元素加起来可以均分到k个数组中。

也就是说，对于这个数组中的每个元素，想要可以构成一个合法的子数组，每个相同元素的数量都需要能够整除k。

然后对于我们选择的子数组，子数组内的元素的每个相同元素的数量是小于等于元素数量除以k的。反正数组外的元素可以随意分配。

考虑使用滑动窗口来解决这个问题。

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n+1);
    vector<int> cnt(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    vector<int> mx(n + 1, 0);
    for(int i = 1; i <= n; i++)
    {
        if(cnt[i] % k != 0)
        {
            cout << 0 << endl;
            return;
        }
        //子数组中的元素i的最大个数
        mx[i] = cnt[i] / k;
    }

    ll ans = 0;
    int l = 1, r = 1;
    vector<int> use(n + 1, 0);
    for(; l <= n && r <= n; r++)
    {
        int val = a[r];
        use[val]++;
        while(use[val] > mx[val])
        {
            use[a[l]]--;
            l++;
        }
        ans += (ll)(r - l + 1);
    }
    cout << ans << endl;
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
```

### F.Gravity Falls

首先我们可以注意到，最终的数组的长度一定是每个数组的长度的最大值。

可以想到一个暴力的做法，直接对这个二维数组排序(sort函数对二维数组排序是按字典序排序)，然后每次从第一个数组长度进行截断，
把剩下的元素重新加入到新的二维数组中去。

```c++
// 暴力
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    int mx = -1;
    for(int i = 0; i < n; i++)
    {
        int len;
        cin >> len;
        mx = max(mx, len);
        for(int j = 0; j < len; j++)
        {
            int x;
            cin >> x;
            a[i].push_back(x);
        }
    }
    vector<int> res;
    while(res.size() < mx)
    {
        int now = res.size();
        sort(a.begin(), a.end());
        for(int i = 0; i < a[0].size(); i++)
        {
            res.push_back(a[0][i]);
        }
        vector<vector<int>> tmp;
        for(int i = 0; i < a.size(); i++)
        {
            if(a[i].size() > res.size() - now)
            {
                vector<int> tmp1;
                for(int j = res.size() - now; j < a[i].size(); j++)
                {
                    tmp1.push_back(a[i][j]);
                }
                tmp.push_back(tmp1);
            }
        }
        a = tmp;
    }
    for(int i = 0; i < mx; i++)
    {
        cout << res[i] << " ";
    }
    cout << "\n";
}
```

这样居然是可以通过的，但是数据量稍微大一点就会TLE。

考虑优化这个算法。

暴力的解法的时间消耗主要是在sort函数上，有没有什么方法可以优化掉这个地方？

可以注意到，我们可以只关注每一位上面的最小值，并且如果我们选择了某一个数组，那么数组长度比选定数组的长度小的数组我们就可以忽略掉了。

我们可以把这些数组按照长度排序，线性的扫一次就可以得到答案。

具体实现请看代码：

```c++
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    for(int i = 0; i < n; i++)
    {
        int len;
        cin >> len;
        for(int j = 0; j < len; j++)
        {
            int x;
            cin >> x;
            a[i].push_back(x);
        }
    }
    vector<int> pos(n);
    for(int i = 0; i < n; i++)
    {
        pos[i] = i;
    }
    //pos里面存的就是从小到大的数组的索引
    sort(pos.begin(), pos.end(), [&](auto x, auto y) -> bool{
        return a[x].size() < a[y].size();
    });

    int bi = 0;
    int w = 0;
    while(true)
    {
        while(bi < n && a[pos[bi]].size() <= w)
        {
            bi++;
        }
        if(bi >= n) 
        {
            break;
        }
        vector<int> c;
        for(int i = bi; i < n; i++)
        {
            c.push_back(pos[i]);
        }
        while(true)
        {
            vector<int> nc;
            int t = 1e9;
            for(int x : c)
            {
                if(a[x][w] < t)
                {
                    t = a[x][w];
                    nc.clear();
                    nc.push_back(x);
                }
                else if(t == a[x][w])//因为每个位置上可能有多个相同的
                {
                    nc.push_back(x);
                }
            }
            // if(nc.empty()) break;
            cout << a[nc[0]][w] << " ";
            w++;
            if(w == a[nc[0]].size()) break;
            c = nc;
        }
    }
    cout << endl;
}
```

### G.Farmer John's Last Wish

对于一个前缀的数组，我们新加一个元素，产生的新的数组的gcd只会小于等于前面数组的gcd。

所以我们在前缀遍历这个数组的时候，需要记录当前数字的因子与之前的gcd是否会产生联系。

```c++
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
                //数量恰好等于当前的数组长度，是选不出来k的
                if(cnt[j] > maxlen && cnt[j] != i)
                {
                    maxlen = cnt[j];
                }
                //但是可能会跟下一个元素不相同，所以需要记录一下
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
```

### End
***