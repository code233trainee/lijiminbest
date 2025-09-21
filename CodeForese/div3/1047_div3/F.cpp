#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    vector<int> posA(n), posB(n);
    for(int i = 0; i < n; i++) posA[i] = i, posB[i] = i;
    sort(posA.begin(), posA.end(), [&](auto x, auto y) -> bool {
        return a[x] > a[y] || (a[x] == a[y] && x < y);
    });
    sort(posB.begin(), posB.end(), [&](auto x, auto y) -> bool {
        return b[x] > b[y] || (b[x] == b[y] && x < y);
    });
    ll res = 0;

    set<int> s;
    // b[i] >= a[i]
    for(int i = 0, pA = 0; i < n; i++)
    {
        while(pA < n && a[posA[pA]] >= b[posB[i]])
        {
            s.insert(posA[pA++]);
        }
        int ei = i;
        while(ei < n && posB[ei] == posB[i])
        {
            if(b[posB[ei]] >= a[posB[ei]])
            {
                auto it = s.lower_bound(posB[ei] + 1);
                if(it != s.begin())
                {
                    it = prev(it);
                    res += ll(*it + 1) * (n - posB[ei]);
                }
            }
            ei++;
        }
        i = ei - 1;
    }

    // b[i] < a[i]
    s.clear();
    for(int i = 0; i < n; i++)
    {
        if(b[posA[i]] < a[posA[i]])
        {
            auto it = s.lower_bound(posA[i]);
            if(it != s.begin())
            {
                it = prev(it);
                res += ll(*it + 1) * (n - posA[i]);
            }
        }
        s.insert(posA[i]);
    }
    cout << res << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}