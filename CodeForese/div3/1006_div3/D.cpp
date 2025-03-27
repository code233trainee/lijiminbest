#include <bits/stdc++.h>
using namespace std;
int n, a[2010], l, r, val;
void solve()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    //数组翻转后，r+1和r，l-1和l的相对顺序不变
    //所以l，r外的逆序对数量不会受到影响
    //影响的只是l，r范围内的逆序对数量
    //由于n*n的范围小，所以我们可以直接暴力求区间
    //
    cin >> n;
    l = 1;
    r = 1;
    val = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        int cntb = 0;
        int cnts = 0;
        for(int j = i; j <= n; j++)
        {
            if(a[j] > a[i])
            {
                //逆序对增加
                cntb++;
            }
            if(a[j] < a[i])
            {
                //逆序对减少
                cnts++;
            }
            //动态的统计逆序对的增减情况
            if(cnts - cntb > val)
            {
                val = cnts - cntb;
                l = i;
                r = j;
            }
        }
    }
    cout << l << " " << r << "\n";
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