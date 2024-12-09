#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num[26]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
    string n;
    getline(cin, n); //遇到换行就停止输入
    //这里不用这个就会出错
    int ans = 0;
    for(int i = 0; i < n.length(); i++)
    {
        if(n[i] >= 'a' && n[i] <= 'z')
        {
            ans += num[n[i] - 'a'];
        }
        if(n[i] == ' ')
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}