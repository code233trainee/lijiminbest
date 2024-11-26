#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    string s1 = "", s2 = "";
    for(int i = 0; i < n - 1; i++)
    {
        s1 += s[i];
        s2.insert(0,1,s[n - 1 - i]) ;
        if(i >= (n - i - 1))
        {
            if(s1 == s2)
            {
                cout << "YES" << endl;
                cout << s1 << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main()
{
    solve();
}