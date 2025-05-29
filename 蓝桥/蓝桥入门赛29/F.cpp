#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin >> x;
    int temp = x;
    int cnt = 0;
    while(x)
    {
        x >>= 1;
        cnt++;
    }
    int t = 1 << cnt;
    cout << (t - 1) - temp + 1 << endl;
    return 0;
}