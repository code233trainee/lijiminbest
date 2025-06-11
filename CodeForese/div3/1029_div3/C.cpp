#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    // int n;
    // cin >> n;
    // vector<int> a(n);
    // vector<set<int>> b(n+1);
    // for (int i = 0; i < n; i++) {
    //     cin >> a[i];
    //     b[a[i]].insert(i);
    // }
    // int splits = 0;
    // int cur = 0;
    // int lastmx = 0;
    // while(cur < n) {
    //     int now = lastmx;
    //     for(int i = cur; i <= now; i++) {
    //         if(b[a[i]].size() >= 2)
    //         {
    //             auto it = b[a[i]].begin();
    //             lastmx = max(lastmx, *(++it));
    //             b[a[i]].erase(b[a[i]].begin());
    //         }
    //         else
    //         {
    //             cout << splits+1 << endl;
    //             return;
    //         }
    //     }
    //     splits++;
    //     cur = now+1;
    // }

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    set<int> s, t;
    s.insert(a[0]);
    int res = 1;
    for(int i = 1; i < n; i++)
    {
        s.erase(a[i]);
        t.insert(a[i]);
        //如果s为空，说明我们找到了下一个包含全部s的段，我们就可以res++了
        if(s.empty())
        {
            res++;
            s = t;
            t.clear();
        }
    }
    cout << res << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
