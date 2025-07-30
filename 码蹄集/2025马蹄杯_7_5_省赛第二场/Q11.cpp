#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int mn = 1;
    int k = 1;
    int last = a[0];
    for(int i = 1; i < n; i++)
    {   
        if(a[i] == last)
        {
            mn = max(mn, k);
            k = 1;
        }
        else
        {
            last = a[i];
            k++;
        }
    }
    cout << mn << endl;
    return 0;
}