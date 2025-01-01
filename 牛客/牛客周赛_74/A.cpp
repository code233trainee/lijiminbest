#include <bits/stdc++.h>
using namespace std;
int main()
{
    int min = INT_MAX;
    for(int i = 0; i < 7; i++)
    {
        int a;
        cin >> a;
        if(a < min)
        {
            min = a;
        }
    }
    cout << min << "\n";
    return 0;
}