#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1; i < n; i++)
    {
        if(((i*i) % n) <= (n/2))
        {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}