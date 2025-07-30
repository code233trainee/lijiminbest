#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> ans;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '#')
        {
            ans.push_back(i+1);
        }
        if(ans.size() == 2)
        {
            cout << ans[0] << ',' << ans[1] << endl;
            ans.clear();
        }
    }
    return 0;
}