#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int day[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int checks(string s)
{
    if(s == "*") return 60;
    int n = s.size();
    vector<int> a;
    bool ok = false;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == ',')
        {
            continue;
        }
        if(s[i] == '-')
        {
            ok = true;
            continue;
        }
        if(s[i] >= '0' && s[i] <= '9')
        {
            int x = 0;
            if(i + 1 < n && s[i+1] >= '0' && s[i+1] <= '9')
            {
                x += (s[i] - '0') * 10 + (s[i+1] - '0');
                i++;
            }
            else
            {
                x += (s[i] - '0');
            }
            a.push_back(x);
        }
    }
    if(ok)
    {
        return a[1] - a[0] + 1;
    }
    else
    {
        return a.size();
    }
}
int checkm(string s)
{
    if(s == "*") return 60;
    int n = s.size();
    vector<int> a;
    bool ok = false;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == ',')
        {
            continue;
        }
        if(s[i] == '-')
        {
            ok = true;
            continue;
        }
        if(s[i] >= '0' && s[i] <= '9')
        {
            int x = 0;
            if(i + 1 < n && s[i+1] >= '0' && s[i+1] <= '9')
            {
                x += (s[i] - '0') * 10 + (s[i+1] - '0');
                i++;
            }
            else
            {
                x += (s[i] - '0');
            }
            a.push_back(x);
        }
    }
    if(ok)
    {
        return a[1] - a[0] + 1;
    }
    else
    {
        return a.size();
    }
}
int checkh(string s)
{
    if(s == "*") return 24;
    int n = s.size();
    vector<int> a;
    bool ok = false;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == ',')
        {
            continue;
        }
        if(s[i] == '-')
        {
            ok = true;
            continue;
        }
        if(s[i] >= '0' && s[i] <= '9')
        {
            int x = 0;
            if(i + 1 < n && s[i+1] >= '0' && s[i+1] <= '9')
            {
                x += (s[i] - '0') * 10 + (s[i+1] - '0');
                i++;
            }
            else
            {
                x += (s[i] - '0');
            }
            a.push_back(x);
        }
    }
    if(ok)
    {
        return a[1] - a[0] + 1;
    }
    else
    {
        return a.size();
    }
}
int checkdAmon(string d, string m)
{
    if(d == "*" && m == "*") return 365;
    // 月数
    vector<int> a;
    bool ok = false;
    if(m == "*")
    {
        for(int i = 1; i <= 12; i++)
        {
            a.push_back(i);
        }
    }
    else
    {
        int n = m.size();
        for(int i = 0; i < n; i++)
        {
            if(m[i] == ',')
            {
                continue;
            }
            if(m[i] == '-')
            {
                ok = true;
                continue;
            }
            if(m[i] >= '0' && m[i] <= '9')
            {
                int x = 0;
                if(i + 1 < n && m[i+1] >= '0' && m[i+1] <= '9')
                {
                    x += (m[i] - '0') * 10 + (m[i+1] - '0');
                    i++;
                }
                else
                {
                    x += (m[i] - '0');
                }
                a.push_back(x);
            }
        }
    }
    // 天数：
    vector<int> ad;
    bool okd = false;
    if(d == "*")
    {
        for(int i = 1; i <= 31; i++)
        {
            ad.push_back(i);
        }
    }
    else
    {
        int g = d.size();
        for(int i = 0; i < g; i++)
        {
            if(d[i] == ',')
            {
                continue;
            }
            if(d[i] == '-')
            {
                okd = true;
                continue;
            }
            if(d[i] >= '0' && d[i] <= '9')
            {
                int x = 0;
                if(i + 1 < g && d[i+1] >= '0' && d[i+1] <= '9')
                {
                    x += (d[i] - '0') * 10 + (d[i+1] - '0');
                    i++;
                }
                else
                {
                    x += (d[i] - '0');
                }
                ad.push_back(x);
            }
        }
        
    }
    vector<int> days;
    if(okd)
    {
        for(int i = ad[0]; i <= ad[1]; i++)
        {
            days.push_back(i);
        }
    }
    else
    {
        for(int i = 0; i < ad.size(); i++)
        {
            days.push_back(ad[i]);
        }
    }
    
    // for(int i = 0; i < a.size(); i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    // for(int i = 0; i < days.size(); i++)
    // {
    //     cout << days[i] << " ";
    // }
    // cout << endl;


    int ans = 0;
    if(ok)
    {
        for(int i = a[0]; i <= a[1]; i++)
        {
            for(int j = 0; j < days.size(); j++)
            {
                if(day[i] >= days[j])
                {
                    ans++;
                }
            }
        }
    }
    else
    {
        int k = a.size();
        for(int i = 0; i < k; i++)
        {
            for(int j = 0; j < days.size(); j++)
            {
                if(day[a[i]] >= days[j])
                {
                    ans++;
                }
            }
        }
    }
    return ans;
}
int main()
{
    
    vector<string> v(5);
    for(int i = 0; i < 5; i++)
    {
        cin >> v[i];
    }
    int a, b, c, d;
    a = checks(v[0]);
    b = checkm(v[1]);
    c = checkm(v[2]);
    d = checkdAmon(v[3], v[4]);
    int ans = a*b*c*d;
    // cout << a << " " << b << " " << c << " " << d << endl;
    cout << ans << endl;
    
    return 0;
}