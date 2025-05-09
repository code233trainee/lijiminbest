#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int a[200005];
int n;
int pre[200], suf[200];
void solve(int init)
{
    for(int i = 2; i <= n; i++)
    {
        suf[a[i]]++;
    }
    int ans = n-1;

    for(int i = 1; i <= n-1; i++)
    {
        int cnt = 0;
        for(int j = init+1; j <= 100; j++)
        {
            cnt += pre[j];
        }
        for(int j = a[i]+1; j <= 100; j++)
        {
            cnt += suf[j];
        }
        ans = min(ans, cnt);
        pre[a[i]]++;
        suf[a[i+1]]--;
    }
    cout << ans << endl;   
}   
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int q;
    cin >> q;
    while(q--)
    {
        int v;
        cin >> v;
        solve(v);
    }
    return 0;
}