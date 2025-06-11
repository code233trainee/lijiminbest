#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.second != b.second)
    {
        return a.second < b.second;
    }
    else
    {
        return a.first > b.first;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    int mx = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
        mx = max(mx, a[i].second);
    }
    sort(a.begin(), a.end(), cmp);
    int tot = 0;
    for(int i = 1; i <= mx; i++)
    {
        for(int j = 0; j < n; j++)
        {
            
        }
    }
    return 0;
}