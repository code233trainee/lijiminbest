#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s;
    cin >> n >> s;
    s = '#' + s;
    for(int i = 1; i <= n; i++)
    {
        string t = s.substr(1, i);
        if(n % i == 0)
        {
            bool ok = true;
            for(int j = 1; j <= n / i; j++)
            {
                if(s.substr(1 + ((j-1) * i), i) != t)
                {
                    ok = false;
                    break;
                }
                
            }
            if(ok)
            {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}