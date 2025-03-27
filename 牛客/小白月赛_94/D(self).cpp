#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) 
{
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1), b(n+1), c(n+1);
    int ok = 1;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(i >= 2 && a[i-1] % a[i] != 0)
        {
            ok = 0;
        }
    }
    if(!ok)
    {
        cout << "-1\n";
        return;
    }
    for(int i = 1; i <= n; i++)
    {
        if(a[i] != a[i-1])
        {
            b[i] = a[i];
        }
        else
        {
            for(int j = b[i-1]; j <= n; j += a[i])
            {
                if(!c[j] && gcd(j, a[i-1]) == a[i])
                {
                    b[i] = j;
                    break;
                }
            }
        }
        if(!b[i])
        {
            cout << "-1\n";
            return;
        }
        c[b[i]] = 1;
    }
    for(int i = 1; i <= n; i++)
    {
        cout << b[i] << " ";
    }
    cout << "\n";
}
int main()
{
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}