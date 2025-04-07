#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    string s;
    cin >> s;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    string ans;
    for(int i = 0; i < s.size()-1; i++)
    {
        if(s[i] < s[i+1] && a[i] >= m)
        {
            ans = s.substr(0, i+1) + s.substr(i, 1) + s.substr(i+1);
            m -= a[i];
        }
    }
    cout << s;
    return 0;
}