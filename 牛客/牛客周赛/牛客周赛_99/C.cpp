#include <bits/stdc++.h>
using namespace std;
string coutc(int cnt, char c)
{
    string s = "";
    for(int i = 0; i < cnt; i++)
    {
        s += c;
    }
    return s;
}
void solve()
{
    int k;
    cin >> k;
    if(k == 0)
    {
        cout << 1 << endl;
    }
    else if(k == 1)
    {
        cout << 4 << endl;
    }
    else
    {
        int cnt = k / 2;
        if(k % 2 == 1)
        {
            cout << 4 << coutc(cnt, '8') << endl;
        }
        else
        {
            cout << coutc(cnt, '8') << endl;
        }
    }
}   
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}