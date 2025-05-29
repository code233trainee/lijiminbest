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
bool check(vector<int> &a)
{
    int n = a.size();
    int g = gcd(a[0], a[1]);
    for(int i = 1; i < n - 1; i++)
    {
        int cur = gcd(a[i], a[i+1]);
        if(cur < g)
        {
            return false;
        }
        g = cur;
    }
    return true;
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
    int g = -1;
    int temp = -1;
    for(int i = 0; i < n - 1; i++)
    {
        int cur = gcd(a[i], a[i+1]);
        if(cur < g)
        {
            temp = i;
            break;
        }
        g = cur;
    }
    if(temp == -1)
    {
        cout << "YES\n";
    }
    else
    {
        vector<int> a1 = a, a2 = a, a3 = a;
        a1.erase(a1.begin()+temp-1);
        a2.erase(a2.begin()+temp);
        if(temp < n - 1)
        {
            a3.erase(a3.begin()+temp+1);
        }
        if(check(a1) || check(a2) || check(a3))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
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