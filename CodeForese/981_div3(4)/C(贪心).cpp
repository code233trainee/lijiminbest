#include <bits/stdc++.h>
using namespace std;
//贪心
int main()
{
    //高效处理输入输出
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<int> b(n);
        for(int j = 0; j < n/2; j++)
        {
            if(j == 0)
            {
                b[j] = a[j];
                b[n-j-1] = a[n-j-1];
            }
            else
            {
                if(b[j-1] == a[j])
                {
                    b[j] = a[n-j-1];
                    b[n-j-1] = a[j];
                }
                else if(b[j-1] == a[n-j-1])
                {
                    b[j] = a[j];
                    b[n-j-1] = a[n-j-1];
                }
                else if(b[n-j] == a[j])
                {
                    b[j] = a[j];
                    b[n-j-1] = a[n-j-1];
                }
                else
                {
                    b[j] = a[n-j-1];
                    b[n-j-1] = a[j];
                }
            }
        }
        if(n&1)
        {
            b[n/2] = a[n/2];
        }
        int ans = 0;
        for(int i = 0; i < n-1; i++)
        {
            if(b[i] == b[i+1])
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
}