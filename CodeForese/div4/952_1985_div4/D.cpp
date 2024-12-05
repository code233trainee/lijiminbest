#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    int x, y;
    vector<string> v(n);
    for(int i = 0;i < n; i++)
    {
        cin >> v[i];
    }
    int nums = 0;
    int index = 0;
    for(index = 0; index < n; index++)
    {
        size_t tt = v[index].find('#');
        if(tt == string::npos)
        {
            continue;
        }
        else
        {
            nums++;
            y = index + 1;
            x = tt + 1;
        }
    }
    if(nums > 1)
    {
        nums /= 2;
    }
    else
    {
        nums = 0;
    }
    cout << y-nums << " " << x << endl;
}
int main()
{
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}