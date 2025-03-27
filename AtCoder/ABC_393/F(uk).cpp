#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;
struct node{
    int id, r, x, ans;
};
node q[N];
int n, m, a[N], k[N], len;
bool cmp1(node d1, node d2)
{
    return d1.r < d2.r;
}
bool cmp2(node d1, node d2)
{
    return d1.id < d2.id;
}
int Find(int num)
{
    int l = 1, r = len, as = 1;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(num <= k[mid])
        {
            as = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return as;
}
int solve(int num)
{
    int l = 1, r = len, as = 0;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(num >= k[mid])
        {
            as = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return as;
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++)
    {
        cin >> q[i].r >> q[i].x;
        q[i].id = i;
    }
    sort(q + 1, q + m + 1, cmp1);
    int now = 1;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] > k[len])
        {
            k[++len] = a[i];
        }
        else
        {
            k[Find(a[i])] = a[i];
        }
        while(now <= m && q[now].r == i)
        {
            q[now].ans = solve(q[now].x);
            now++;
        }
    }
    sort(q + 1, q + m + 1, cmp2);
    for(int i = 1; i <= m; i++)
    {
        cout << q[i].ans << "\n";
    }
    return 0;
}