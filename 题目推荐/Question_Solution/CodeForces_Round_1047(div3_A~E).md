# CodeForces Round 1047(div3 A~E)

竞赛地址：https://codeforces.com/contest/2137

### A.Collatz Conjecture

给定的k的范围很小，我们可以把x看成是一直用操作一得来的

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int k, x;
    cin >> k >> x;
    for(int i = 1; i <= k; i++)
    {
        x *= 2;
    }
    cout << x << endl;
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

### B.Fun Permutation

想让每个数字都是3的倍数是很难做到的。我们可以注意到n是大于等于2的，由于给定的是排列，所以我们可以构造出每个数字相加之后都是等于n+1的。

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cout << n + 1 - x << " ";
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

### C.Maximum Even Sum

让a乘上一个数字带来的贡献是很大的，所以我们应该尽可能的让k变大。

分类讨论：

1. a,b均为偶数，我们可以让k = b / 2, 这样a = ab/2, b = 2, 相加之后依然为偶数。
2. a,b均为奇数，令k = b, 然后a = ab，b = 1，相加之后依然为偶数。
3. a为奇数，b为偶数，此时令k = b无法构造出a+b等于偶数，但是如果b有4这个因子，也就是k = b/2时为偶数，我们就可以构造出a = ab/2，b = 2，相加之后为偶数。
4. a为偶数，b为奇数，此时无法构造出a+b=偶数的情况，直接输出-1。

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll a, b;
    cin >> a >> b;
    if( a % 2 == 1 && b % 2 == 1)
    {
        cout << a * b + 1 << endl;
    }
    else if(a % 2 == 0 && b % 2 == 0)
    {
        cout << a * b / 2 + 2 << endl;
    }
    else if(a % 2 == 1 && b % 4 == 0)
    {
        cout << a * b / 2 + 2 << endl;
    }
    else
    {
        cout << -1 << endl;
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

### D.Replace with Occurrences

对于每个a位置上的ai，找到对应的数组b，使得f(ai) = bi。如果不能则输出-1。

想要可以构造出这样一个数组b，我们需要对于a中出现的数字次数，是合法的，意思就是对于ai，cnt[ai] % ai = 0，我们才可能构造出来。

本题的一些代码细节需要注意。

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), cnt(n+1);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for(int i = 1; i <= n; i++)
    {
        if(cnt[i] && cnt[i] % i != 0)
        {
            //如果不符合
            cout << -1 << endl;
            return;
        }
    }
    //使用的数字从1开始
    int now = 1;
    vector<int> p(n+1, 0), b(n+1, 0);
    for(auto &z : a)
    {
        //p代表当前ai使用的数字，每当p[z] % z = 0时，说明已经使用过一次now来构造这个数组，所以b对应的数字需要更新
        if(p[z] % z == 0)
        {
            b[z] = now++;
        }
        cout << b[z] << " ";
        p[z]++;
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

### E.Mexification

通过对样例的模拟和手造几组样例发现，最终的数组总是在两个状态里面来回跳转。

例如：6 6 2 4 3 0 1 8，最终在6 6 **2 4 3 0 1** 6和5 5 **2 4 3 0 1** 5来回转换。

0 1 2 3 9 7 4，最终在 0 1 2 3 5 5 4和0 1 2 3 6 6 4来回转换。

并且达到最终的状态所需要的次数并不是很多，所以我们可以暴力的去找最终的状态，然后在判断剩余的k是否会发生状态的转化。

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> cnt(n+1);
    vector<ll> last(n+1, -1), next(n+1, 0);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    while(k)
    {
        k--;
        int now = 0;
        while(cnt[now]) now++;
        next.assign(n+1, 0);//重新赋值为全0
        for(int i = 0; i <= n; i++)
        {
            //cnt[i] = 1且是小于整个数组的mex的
            if(i < now && cnt[i] == 1)
            {
                next[i] += cnt[i];
            }
            else
            {
                next[now] += cnt[i];
            }
        }
        if(last == next)
        {
            break;
        }
        last = cnt;
        cnt = next;
    }

    // last cnt next
    // 上次 当前 下次
    auto res = cnt;
    if(k % 2 == 0) 
    {
        res = next;
    }
    else
    {
        res = cnt;
    }
    ll ans = 0;
    for(int i = 0; i <= n; i++)
    {
        ans += (ll)i * res[i];
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
### End
***