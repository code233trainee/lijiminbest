#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n - 1; i++)
    {
        cin >> b[i];
    }
    sort(a.begin(), a.end(), cmp);
    sort(b.begin(), b.end(), cmp);
    // int idx = 0;
    // long long cnt = 0;
    // int min = INT_MAX;
    // bool ok = true;
    // for(int i = 0 ; i < n && idx < n - 1; i++)
    // {
    //     if(b[idx] < a[i])
    //     {
    //         cnt++;
    //         if(a[i] <= min)
    //         {
    //             min = a[i];
    //         }
    //     }
    //     else
    //     {
    //         idx++;
    //     }
    //     if(cnt >= 2)
    //     {
    //         ok = false;
    //         break;
    //     }
    // }
    // if(ok)
    // {
    //     cout << min << "\n";
    // }
    // else
    // {
    //     cout << -1 << "\n";
    // }
    //上面不知道为什么会挂两个测试点

    int i = 0;
    while(i < n - 1 && b[i] >= a[i])
    {
        i++;
    }
    for(int j = i; j < n - 1; j++)
    {
        if(b[j] < a[j + 1])
        {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << a[i] << endl;
    return 0;
}