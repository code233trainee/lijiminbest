#include <bits/stdc++.h>
using namespace std;
void check(vector<int> &a, string &ys, string &s)
{
    int cnt = 1;
    if(s.size() == 1)
    {
        a.push_back(1);
        ys = s;
        return;
    }
    for(int i = 0; i < s.size(); i++)
    {
        if(i == s.size()-1)
        {
            if(s[i] == s[i-1])
            {
                ys+=s[i];
                a.push_back(cnt);
                cnt = 1;
            }
            else
            {
                ys += s[i];
                a.push_back(cnt);
                cnt = 1;
            }
            break;
        }
        if(s[i] != s[i+1])
        {
            ys += s[i];
            a.push_back(cnt);
            cnt = 1;
        }
        else
        {
            cnt++;
        }
    }
}
void solve()
{
    string p, s;
    cin >> p >> s;
    if(s.size() > 2 * p.size())
    {
        cout << "NO\n";
        return;
    }
    string ts = "";
    string tp = "";
    vector<int> as;
    vector<int> ap;
    check(as, ts, s);
    check(ap, tp, p);
    if(ts != tp)
    {
        cout << "NO" << "\n";
        return;
    }
    for(int i = 0; i < ts.size(); i++)
    {
        if(as[i] > 2*ap[i] || as[i] < ap[i])
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    // for(int i = 0; i < as.size(); i++)
    // {
    //     cout << as[i] << " ";
    // }
    // cout << ts;
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