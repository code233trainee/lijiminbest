#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if(i&1)
        {
            sum += x;
        }
    }
    cout << sum;
    return 0;
}