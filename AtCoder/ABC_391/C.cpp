#include <bits/stdc++.h>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n+1);
    vector<int> t(n+1);
    for(int i = 1; i <= n; i++)
    {
        a[i] = 1;
        t[i] = i;
    }
    int cnt = 0;
    while(q--)
    {
        int e;
        cin >> e;
        if(e == 1)
        {
            int c, d;
            cin >> c >> d;
            a[t[c]]--;
            a[d]++;
            if(a[t[c]] == 1)
            {
                cnt--;
            }
            if(a[d] == 2)
            {
                cnt++;
            }
            t[c] = d;
        }
        else
        {
            cout << cnt << "\n";
        }
    }
    return 0;
}