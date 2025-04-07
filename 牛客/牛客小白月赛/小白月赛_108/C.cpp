#include <bits/stdc++.h>
using namespace std;
int main()
{
    // 链接：https://ac.nowcoder.com/acm/contest/99287/C
    // 根据题中所给的信息，我们的分组中的每一个数字都是相同的
    int t;
    cin >> t;
    while(t--)
    {
        int n, m = 0, i, j;
        cin >> n;
        map<int, int> c;
        while(n--)
        {
            int x;
            cin >> x;
            c[x]++;
        }
        for(auto [x, y] : c)
        {
            // 如果相同的数字有偶数个，则违背了相异不为0的条件件，所以需要再加一组分组
            m += 1 + (y % 2 == 0);
        }
        cout << m << "\n";
    }
    return 0;
}