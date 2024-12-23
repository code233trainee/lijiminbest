#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    while(n)
    {
        int temp = n;
        int total = 0;
        while(temp)
        {
            total += temp % 10;
            temp /= 10;
        }
        n = n - total;
        cnt++;
    }
    cout << cnt << "\n";
    return 0;
}