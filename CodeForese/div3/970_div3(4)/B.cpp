#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int m = 1;
    while(m*m < n)
    {
        m++;
    }
    string s;
    cin >> s;
    if(m*m != n)
    {
        cout << "NO" << endl;
        return;
    }
    vector<string> ss(m, string(m, '0'));
    for(int i = 0; i < m ; i++)
    {
        ss[0][i] = '1';
        ss[i][0] = '1';
        ss[i][m - 1] = '1';
        ss[m - 1][i] = '1';
    }
    string sss = "";
    for(const auto &z : ss)
    {
        sss+=z;
    }
    cout << ((sss == s) ? "YES" : "NO") << endl;
}
int main()
{
    //高效处理输入输出
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int t = 0;
    cin >> t;
    while(t--)
    {
        solve();
    }
}