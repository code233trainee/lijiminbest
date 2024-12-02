#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, n;
    cin >> a >> b >> n;
    while(n--)
    {
        int len;
        cin >> len;
        double maxx = max(a, b);
        double tt = sqrt(a*a + b*b);
        maxx = max(maxx, tt);
        if(len < maxx)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    } 
}