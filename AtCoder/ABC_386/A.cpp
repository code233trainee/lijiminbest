#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<int, int> ans;
    for(int i = 0; i < 4; i++)
    {
        int a;
        cin >> a;
        ans[a]++;
    }
    if(ans.size() == 2)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}