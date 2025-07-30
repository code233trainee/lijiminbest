#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector f(n, vector<bool>(n));
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if(u > v)
        {
            swap(u, v);
        }
        f[u][v] = true;
    }
    int ans = 100;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        a[i] = i;
    }
    do{
       // cycle * 1
        vector g(n, vector<bool>(n));
        for(int i = 0; i < n; i++)
        {
                int u = a[i];
                int v = a[(i + 1) % n];
                if(u > v)
                {
                    swap(u, v);
                }
                g[u][v] = true;
        }
        int c0 = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(f[i][j] != g[i][j])
                {
                    c0++;
                }
            }
        }
        if(c0 < ans)
        {
            ans = c0;
        }
        
        // cycle * 2
        for(int d = 3; d <= n - 3; d++)
        {
            vector h(n, vector<bool>(n));
            for(int i = 0; i < d; i++)
            {
                int u = a[i];
                int v = a[(i+1) % d];
                if(u > v)
                {
                    swap(u, v);
                }
                h[u][v] = true;
            }
            for(int i = 0; i < n - d; i++)
            {
                int u = a[i + d];
                int v = a[(i+1) % (n-d) + d];
                if(u > v)
                {
                    swap(u, v);
                }
                h[u][v] = true;
            }
            int c1 = 0;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(f[i][j] != h[i][j])
                    {
                        c1++;
                    }
                }
            }
            if(c1 < ans)
            {
                ans = c1;
            }
        }
    } while (next_permutation(a.begin(), a.end()));
    cout << ans << "\n";
    return 0;
}