#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    string s;
    cin >> s;
    s = "x" + s;
    vector<int> a(11);
    for(int i = 1; i <= 10; i++)
    {
        a[s[i]-'0']++;
    }
    for(int i = 1; i <= 10; i++)
    {
        for(int j = 1; j <= 10; j++)
        {
            if(a[10 - i + j - 1])
            {
                cout << 10 - i + j - 1;
                a[10 - i + j - 1]--;
                break;
            }
        }
    }
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}