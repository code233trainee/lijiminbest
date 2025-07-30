#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool ok = false;
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        while(s[i] != 'z' && i < n)
        {
            if(!ok)
            {
                cnt = 25 - (s[i] - 'a');
                s[i] = s[i] + cnt;
            }
            else
            {
                int k = s[i] - 'a';
                if(k + cnt <= 25)
                {
                    s[i] = s[i] + cnt;
                }
                else
                {
                    break;
                }
            }
            i++;
            ok = true;
        }   
        if(ok)
        {
            break;
        }
    }
    cout << s << endl;
    return 0;
}