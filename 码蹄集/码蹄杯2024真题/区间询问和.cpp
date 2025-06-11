#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n+2), b(n+1);;
    for(int i = 1; i <= n; i++) cin >> b[i];
    sort(b.begin() + 1, b.end(), greater<int>());
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        a[l]++;
        a[r+1]--;
    }
    for(int i = 1; i <= n; i++)
    {
        a[i] = a[i-1] + a[i];
    }
    sort(a.begin()+1, a.begin()+1+n, greater<int>());
    ll total = 0;
    for(int i = 1; i <= n; i++)
    {
        total += 1ll * a[i] * b[i];
    }
    cout << total << endl;
    return 0;
}