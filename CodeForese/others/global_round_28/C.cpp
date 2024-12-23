#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    // int l = 0;
    // int cnt1 = 0;
    // int cnt0 = 0;
    // bool ok = false;
    // int first = 0;
    // while(l < n)
    // {
    //     if(s[l] == '1')
    //     {
    //         if(ok)
    //         {
    //             break;
    //         }
    //         cnt1++;
    //         l++;
    //     }
    //     else
    //     {
    //         if(!ok)
    //         {
    //             first = l;
    //         }
    //         l++;
    //         cnt0++;
    //         ok = true;
    //     }
    // }
    // if(cnt0 == 0)
    // {
    //     cout << 1 << " " << n;
    //     cout << " " << 1 << " " << 1;
    //     cout << "\n";
    //     return;
    // }
    // if(cnt0 != 0 && (cnt1 + cnt0 == n))
    // {
    //     cout << 1 << " " << n;
    //     cout << " " << 1 << " " << cnt0;
    //     cout << "\n";
    //     return;
    // }
    // if(cnt0 >= cnt1)
    // {
    //     cout << 1 << " " << n;
    //     cout << " " << 1 << " " << n - cnt1;
    //     cout << "\n";
    // }
    // else
    // {
    //     cout << 1 << " " << n;
    //     //first is index of first 0
    //     cout << " " << first - cnt0 + 1 << " " << n-1;
    //     cout << "\n";
    // }   
    cout << 1 << " " << n << " ";
    int first_1 = 0;
    int first_0 = n + 1;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '1')
        {
            first_1 = i + 1;
            break;
        }
    }
    for(int i = first_1 - 1; i < n; i++)
    {
        if(s[i] == '0')
        {
            first_0 = i + 1;
            break;
        }
    }
    int len = n + 1 - first_0;
    if(!len)
    {
        //len决定了选择的第二个子字符串的长度
        len = 1;
    }
    auto XOR = [&](int l, int r) -> string
    {
        l--;
        r--;
        string ret = s;
        int dif = n - 1 - r;
        for(int i = l + dif; i < n; i++)
        {
            if(s[i] != s[i - dif])
            {
                ret[i] = '1';
            }
            else
            {
                ret[i] = '0';
            }
        }
        return ret;
    };
    string ans = string(n, '0');
    for(int i = first_1; i + len - 1 <= n; i++)
    {
        ans = max(ans, XOR(i, i + len - 1));
    }
    for(int i = first_1; i + len - 1 <= n; i++)
    {
        if(ans == XOR(i, i + len - 1))
        {
            cout << i << " " << i + len - 1 << "\n";
            break;
        }
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
