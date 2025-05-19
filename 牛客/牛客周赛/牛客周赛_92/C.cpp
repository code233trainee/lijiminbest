#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if(n == 1 || n == 2)
    {
        cout << "-1\n";
    }
    else
    {
        cout << "1 ";
        for(int i = n; i >= 2; i--)
        {
            cout << i << " ";
        }
    }
    cout << "\n";
    return 0;
}