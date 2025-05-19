#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, a[500010], c[500010];
ll ans = 0;

//归并排序
void msort(int b, int e)
{
    if(b == e)
    {
        return;
    }
    int mid = (b + e) / 2;
    int i = b;
    int j = mid + 1;
    int k = b;
    msort(b, mid);
    msort(mid+1, e);
    while(i <= mid && j <= e)
    {
        if(a[i] <= a[j])
        {
            c[k++] = a[i++];
        }
        else
        {
            c[k++] = a[j++];
            // 统计逆序对
            ans += mid - i + 1;
        }
    }
    while(i <= mid)
    {
        c[k++] = a[i++];
    }
    while(j <= e)
    {
        c[k++] = a[j++];
    }
    for(int l = b; l <= e; l++)
    {
        a[l] = c[l];
    }
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    msort(1, n);
    for(int i = 1; i <= n; i++)
    {
        cout << a[i] << " \n"[i == n];
    }
    cout << ans << endl;
    return 0;
}