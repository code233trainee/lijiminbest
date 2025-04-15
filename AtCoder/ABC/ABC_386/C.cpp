#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    string s, t;
    cin >> k >> s >> t;
    int ss = s.size();
    int st = t.size();
    if(ss == st)
    {
        int cnt = 0;
        for(int i = 0; i < ss; i++)
        {
            if(s[i] != t[i])
            {
                cnt++;
            }
        }
        if(cnt > 1)
        {
            cout << "No\n";
        }
        else
        {
            cout << "Yes\n";
        }
        return 0;
    }
    else if(ss == st - 1)// s长度小于t
    {
        int cnt = 0;
        bool check = false;
        for(int i = 0; i < ss; i++)
        {
            if(!check)
            {
                if(s[i] != t[i])
                {
                    check = true;
                    cnt++;
                    i--;
                }
            }
            else
            {
                if(s[i] != t[i+1])
                {
                    cnt++;
                }
            }
        }
        cout << (cnt > 1 ? "No" : "Yes") << "\n";
        return 0;
    }
    else if(ss - 1 == st)// s长度大于t
    {
        int cnt = 0;
        bool check = false;
        for(int i = 0; i < st; i++)
        {
            if(!check)
            {
                if(s[i] != t[i])
                {
                    check = true;
                    cnt++;
                    i--;
                }
            }
            else
            {
                if(s[i+1] != t[i])
                {
                    cnt++;
                }
            }
        }
        cout << (cnt > 1 ? "No" : "Yes") << "\n";
        return 0; 
    }
    cout << "No\n";
    return 0;
}