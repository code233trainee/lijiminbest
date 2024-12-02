#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> v1(n+1, vector<int>(26, 0));
    vector<vector<int>> v2(n+1, vector<int>(26, 0));
    //记录字母出现的次数
    for(int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        v1[i][c - 'a']++;
        for(int j = 0; j < 26; j++)
        {
            v1[i][j] += v1[i-1][j];
        }
    }
     
    for(int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        v2[i][c -'a']++;
        for(int j = 0; j < 26; j++)
        {
            v2[i][j] += v2[i-1][j];
        }
    }
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        for(int i = 0; i < 26; i++)
        {
            //l-1指的是出现之前的状态
            int a = v1[r][i] - v1[l - 1][i];
            int b = v2[r][i] - v2[l - 1][i];
            ans += abs(a - b);
        }   
        //除以2是因为我们求的是当v1中没出现的字符在v2中出现了，v2中没出现的字符在v1中出现，我们要使这个字符串相同只需要改一个就可以了，所以要除以2
        cout << ans / 2 << endl;
    }
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