#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    while(n--)
    {
        int t = 0;
        cin >> t;
        if(t&1)
        {
            cout << "Kosuke" << endl;
        }
        else
        {
            cout << "Sakurako" << endl;
        }
    }
}