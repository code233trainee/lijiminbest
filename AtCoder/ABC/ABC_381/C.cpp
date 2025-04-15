#include <bits/stdc++.h>
using namespace std;
//前缀和
namespace solve{
    int ans = 0, n;
    int per[200005], suf[200005];
    string s;
    void MAIN()
    {
        cin >> n >> s;
        s +=" ";
        s = " " + s;
        for(int i = 1; i <= n; i++)
        {
            if(s[i] == '1')
            {
                per[i] = per[i-1] + 1;
            }
        }
        for(int i = n; i >= 1; i--)
        {
            if(s[i] == '2')
            {
                suf[i] = suf[i+1] + 1;
            }
        }
        for(int i = 1; i <= n; i++)
        {
            if(s[i] == '/')
            {
                ans = max(ans, min(per[i-1], suf[i+1]));
            }
        }
        cout << ans*2 + 1 << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve::MAIN();
}