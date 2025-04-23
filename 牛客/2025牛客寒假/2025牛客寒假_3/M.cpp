#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int cntc = 0, cntd = 0, cnte = 0, cntn = 0, cnto = 0, cntr = 0, cntw = 0;
    for(int i = 0; i < 8; i++)
    {
        if(s[i] == 'c')
        {
            cntc++;
        }
        else if(s[i] == 'd')
        {
            cntd++;
        }
        else if(s[i] == 'e')
        {
            cnte++;
        }
        else if(s[i] == 'n')
        {
            cntn++;
        }
        else if(s[i] == 'o')
        {
            cnto++;
        }
        else if(s[i] == 'r')
        {
            cntr++;
        }
        else if(s[i] == 'w')
        {
            cntw++;
        }
    }
    if(cntc >= 1 && cntd >= 1 && cnte >= 1 && cntn >= 1 && cnto >= 2 && cntr >= 1 && cntw >= 1)
    {
        cout << "happy new year" << endl;
    }
    else
    {
        cout << "I AK IOI" << endl;
    }
}
int main()
{
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}