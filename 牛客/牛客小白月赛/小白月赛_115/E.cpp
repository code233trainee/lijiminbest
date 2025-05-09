#include <bits/stdc++.h>
using namespace std;
//允许重复元素的set
multiset<int> sa, sb;
int n, a, upc;
void solve()
{
    if(n * 2 > upc)
    {
        cout << "NO\n";
        return;
    }
    for(int p = 1; p <= upc; p++)
    {
        if(sa.empty() && sb.empty())
        {
            cout << "YES\n";
            return;
        }
        if(!sb.empty() && *sb.begin() < p)
        {
            cout << "NO\n";
            return;
        }
        if(sa.empty())
        {
            map<int, bool> mp;
            for(auto it = sb.begin(); it != sb.end(); it++)
            {
                if(*it < p || mp[*it])
                {
                    cout << "NO\n";
                    return;
                }
                mp[*it] = 1;
            }
            cout << "YES\n";
            return;
        }
        int q = *sa.begin();
        if(!sa.empty() && q < p)
        {
            cout << "NO\n";
            return;
        }
        if(p == q)
        {
            sa.erase(sa.begin());
            sb.insert(p+1);
            continue;
        }
        if(q == p+1)
        {
            if(sb.count(p))
            {
                sb.erase(sb.begin());
                continue;
            }
            sa.erase(sa.begin());
            sb.insert(q+1);
            continue;
        }
        if(*sb.begin() == p)
        {
            sb.erase(sb.begin());
        }
        else
        {
            if(sb.count(q-1) != 0)
            {
                sa.erase(sa.begin());
                sb.insert(q+1);
            }
            else
            {
                sa.erase(sa.begin());
                sb.insert(q-1);
            }
        }
    }
    cout << "YES\n";
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        upc = -1;
        sa.clear();
        sb.clear();
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> a;
            upc = max(upc, a);
            sa.insert(a);
        }
        upc++;
        solve();
    }
    return 0;
}