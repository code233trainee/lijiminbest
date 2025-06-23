#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int check(int a)
{
    int tot = 0;
    while(a)
    {
        int k = a % 10;
        a /= 10;
        tot += k;
    }
    return tot;
}
int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ans += check(x);
    }
    cout << ans << endl;
    return 0;
}