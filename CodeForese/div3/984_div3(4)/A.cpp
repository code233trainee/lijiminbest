#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        
        bool isyes = false;
        for(int j = 0; j < n - 1; j++)
        {
            if( abs(a[j] - a[j+1]) != 5 && abs(a[j] - a[j+1]) != 7)
            {
                cout << "NO" << endl;
                isyes = true;
                break;
            }
        }
        if(!isyes)
        {
            cout << "YES" << endl;
        }
    }

}