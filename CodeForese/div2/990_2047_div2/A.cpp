#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)
    {
        int b;
        cin >> b;
        a[i] = a[i-1] + b;
    }
    vector<int> temp(101);
    for(int i = 1; i <= 100; i++)
    {
        if(i == 1)
        {
            temp[i] = 1; 
        }
        else
        {
            temp[i] = temp[i-1] + ((1 + (i * 2) - 2 ) * 4 - 4);
        }
    }
    int ans = 0;
    int index = 1;
    for(int i = 1; i <= n; i++)
    {
        if(temp[index] == a[i])
        {
            ans++;
            index++;
        }
        else if(temp[index] > a[i])
        {
            continue;
        }
        else
        {
            while(temp[index] < a[i] && index <= 100)
            {
                index++;
            }
            if(temp[index] == a[i])
            {
                ans++;
                index++;
            }
        }
    }
    cout << ans << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}