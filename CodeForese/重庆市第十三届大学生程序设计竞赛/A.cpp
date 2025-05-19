#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> s;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        s.insert(a[i]);
    }
    if(s.size() == 1)
    {
        cout << "0\n";
        return;
    }
    int t = 0;
    while(true)
    {
        t++;
        for(int i = 0; i < n; i++)
        {
            a[i] = a[(t+i)%n] | a[i];
        }
        int mx = *(max_element(a.begin(), a.end()));
        int mn = *(min_element(a.begin(), a.end()));
        if(mx == mn)
        {
            cout << t << "\n";
            break;
        }
    }
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