#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int res = 0;
    while(n--)
    {
        int a, b;
        cin >> a >> b;
        if(b > a)
        {
            res++;
        }
    }
    cout << res << endl;
    return 0;
}