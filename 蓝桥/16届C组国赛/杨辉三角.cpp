#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(100000+10);
    a[1].push_back(1);
    for(int i = 2; i <= 1000; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(j == 0 || j == i-1)
            {
                a[i].push_back(1);
                continue;
            }
            a[i].push_back(a[i-1][j-1]+a[i-1][j]);
        }
    }
    map<int, int> ma;
    for(int i = 1; i <= 1000; i++)
    {
        for(int j = 0; j < a[i].size(); j++)
        {
            if(a[i][j] >= 2 && a[i][j] <= n)
            {
                ma[a[i][j]]++;
            }
        }
    }
    map<int, int> ans;
    for(auto z : ma)
    {
        ans[z.second]++;
    }
    for(auto z : ans)
    {
        cout << z.first << " " <<z.second << endl;
    }
    return 0;
}