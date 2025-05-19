#include <bits/stdc++.h>
using namespace std;
int check(string s)
{
    vector<int> num;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '/')
        {
            break;
        }
        num.push_back(s[i]-'0');
    }
    int ans = 0;
    for(int i = 0; i < num.size(); i++)
    {
        ans += num[i]*(int)(pow(10.0, (double)num.size()-i-1));
    }
    return ans;
}
bool cmp(pair<string, string> a, pair<string, string> b)
{
    if(check(a.second) != check(b.second))
    {
        return check(a.second) > check(b.second);
    }
    else
    {
        return a.first < b.first;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<pair<string, string>> s(n);
    for(int i = 0; i < n; i++)
    {
        cin >> s[i].first;
    }
    for(int i = 0; i < n; i++)
    {
        cin >> s[i].second;
    }
    sort(s.begin(), s.end(), cmp);
    cout << s[0].first << endl;
    return 0;
}