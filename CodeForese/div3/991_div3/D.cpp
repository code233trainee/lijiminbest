#include <bits/stdc++.h>
using namespace std;
void solve()
{
    //tourist
    // string s;
    // cin >> s;
    // //将字符串进行翻转
    // //对于数字字符串就是左边变为低位
    // reverse(s.begin(), s.end());
    // for(int i = int(s.size()) - 1; i >= 0; i--)
    // {
    //     int best = i;
    //     int val = int(s[i] - '0');
    //     for(int j = i; j >= max(0, i - 9); j--)
    //     {
    //         int cur = int(s[j] - '0') - (i - j);
    //         if(cur > val)
    //         {
    //             val = cur;
    //             best = j;
    //         }
    //     }
    //     //旋转，三个参数分别是要移动的起始位置，旋转的中心点，旋转的结束位置
    //     rotate(s.begin() + best, s.begin() + best + 1, s.begin() + i + 1);
    //     s[i] = char('0' + val);
    // }
    // //还原
    // reverse(s.begin(), s.end());
    // cout << s << "\n";


    //jiangly
    //主要思路就是直接模拟
    //要求字典序最大，就要求最大的能够放在前面的数字
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n; i++)
    {
        int k = i;
        for(int j = i; j < n && j < i + 10; j++)
        {
            if(s[j] - j > s[k] - k)
            {
                k = j;
            }
        }
        //按顺序前移
        //最坏复杂度是O(n*9)
        while(k > i)
        {
            s[k]--;
            swap(s[k-1], s[k]);
            k--;
        }
    }
    cout << s << "\n";
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