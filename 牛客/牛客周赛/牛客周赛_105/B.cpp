#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n - 1; i++)
    {
        a[i] = a[i] ^ a[i+1];
    }
    int g = a[0];
    for(int i = 1; i < n - 1; i++)
    {
        g = gcd(g, a[i]);
    }
    cout << g << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    //cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}