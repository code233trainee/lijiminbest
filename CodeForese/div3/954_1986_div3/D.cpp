#include <bits/stdc++.h>
using namespace std;
const int N = 20 + 5;
int a[N];
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = INT_MAX;
    //n最多为20，我们可以直接遍历所有可能的两位数字
    for(int st = 0; st < n - 1; st++)
    {
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(i == st)
            {//两位数字
                a[cnt++] = 10 * (s[i] - '0') + (s[i + 1] - '0');//ascii码，减去'0'取出数字
                i++;
            }
            else
            {
                a[cnt++] = (s[i] - '0');
            }
        }
        int val = 0;
        //遍历我们存进去的数字
        for(int i = 0; i < cnt; i++)
        {
            if(a[i] == 0)//如果这组数字里面有0
            {
                val = -1;
                break;
            }
            if(a[i] == 1)
            {
                continue;
            }
            val += a[i];
        }
        if(!val)
        {
            val = 1;//如果val为0
        }
        if(val == -1)
        {
            val = 0;
        }
        ans = min(ans, val);
    }
    cout << ans << "\n";
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}