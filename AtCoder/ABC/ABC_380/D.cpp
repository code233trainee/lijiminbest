#include <bits/stdc++.h>
using namespace std;
int q, n;
string s;
int main()
{
    cin >> s;
    n = s.size();
    s=" " + s;
    cin >> q;
    while(q--)
    {
        long long k, p=n;
        cin >> k;
        while(k>p)
        {
            p <<= 1;
        }
        bool flag = false;
        while(k>n)
        {
            long long tmp = k;
            if(tmp>(p/2))
            {
                tmp -= p/2;
                flag = !flag;    
            }
            k=tmp;
            p/=2;
        }
        if(flag)
        {
            if(s[k] >= 'A' && s[k] <= 'Z')//如果是大写(这里比较的是ascii码)
            {
                cout << char(s[k]+32) << " ";//转成小写(大小写相差32，大写字母的ascii码值比小写字母的ascii码值小32)
            }
            else//否则
            {
                cout << char(s[k]-32) << " ";//转成大写
            }
        }
        else
        {
            cout << s[k] << " ";
        }
    }
    
}