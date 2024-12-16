#include <bits/stdc++.h>
using namespace std;
bool isComp[100000005];
int main()
{
    int n;
    cin >> n;
    int ans = 0;
    isComp[1] = 1;
    //线性筛
    for(int i = 2; i*i <= n; i++)
    {
        if(isComp[i] == 0)//如果是素数
        {
            for(int j = i*i; j <= n; j += i)//将他的倍数标记为合数
            {
                isComp[j] = 1;
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(isComp[i] == 0)
        {
            if(isComp[i] == 0)
            {
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}