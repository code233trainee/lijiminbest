#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int q;
    cin >> q;
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        int k = 0;
        for(int i = l; i <= r; i++)
        {
            if(i == l)
            {
                cout << a[i] << " ";
                k += a[i];
            }
            else
            {
                cout << a[i] - k << " "; 
                k += a[i] - k;
            }
        
        }
        cout << endl;
    }
    return 0;
}