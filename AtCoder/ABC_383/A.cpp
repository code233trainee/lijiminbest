#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int nn = n;
    int t = 0;
    int v = 0;
    int lastTime = 0;
    int total = 0;
    while(n--)
    {
        cin >> t >> v;
        if(n == nn-1)
        {
            lastTime = t;
            total = v;
            continue;
        }
        total = max(0, total - t + lastTime);
        total += v;
        lastTime = t;
    }
    cout << total;
    return 0;
}