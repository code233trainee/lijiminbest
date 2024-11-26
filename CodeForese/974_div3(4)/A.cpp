#include <bits/stdc++.h>
using namespace std;
int main()
{
    //高效处理输入输出
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        int ans = 0;
        int a = 0;
        int count = 0;
        while(n--)
        {
            cin >> a;
            if(a >= k)
            {
                ans += a;
            }
            else if(a == 0)
            {
                if(ans > 0)
                {
                    ans--;
                    count++;
                }
            }
        }
        cout << count << endl;
    }
}