#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    if(n % 3 == 0)
    {
        for(int i = 1; i <= n; i++)
        {
            a[i] = i;
        }
        for(int i = 1; i <= n; i++)
        {
            if(i % 3 == 0)
            {
                swap(a[i], a[i-1]);
            }
        }
        for(int i = 1; i <= n; i++)
        {
            cout << a[i] << " ";
        }
    }
    else
    {
        cout << "Baka!" << "\n";
    }
    return 0;
}