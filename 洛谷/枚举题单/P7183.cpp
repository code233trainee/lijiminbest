#include <bits/stdc++.h>
using namespace std;
int main()
{
    //AsssBdFg
    string s;
    cin >> s;
    int n = s.length();
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        //位置随插入的字符数量(ans)改变
        if(isupper(s[i]) && (i+ans) % 4 != 0)
        {
            ans += 4 - (i + ans) % 4;
        }
    }
    cout << ans << endl;
    return 0;
}