#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> s(n);
    vector<int> t(n);
    map<int, int> ma;
    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
        s[i] = min(s[i] % k, (k - s[i] % k));
        ma[s[i]]++;
    }
    for(int i = 0; i < n; i++)
    {
        cin >> t[i];
        t[i] = min(t[i] % k, (k - t[i] % k));
        ma[t[i]]--;
    }
    for(auto z : ma)
    {
        if(z.second != 0)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
void solve2()
{
    int n, k;
    cin >> n >> k;
    multiset<int> s;
    multiset<int> t;
    int temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        s.insert(min(temp % k, (k - temp % k)));
    }
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        t.insert(min(temp % k, (k - temp % k)));
    }
    if(s == t)
    {
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        solve2();
    }
    return 0;
}