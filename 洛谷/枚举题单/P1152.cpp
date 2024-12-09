#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<bool> jujm(n);
    bool ok = false;
    for(int i = 0; i < n - 1; i++)
    {
        int k = abs(a[i] - a[i+1]);
        if(k >= 1 && k <= n-1)
        {
            jujm[k] = true;
        }
    }
    for(int i = 1; i < n - 1; i++)
    {
        if(jujm[i])
        {
            continue;
        }
        else
        {
            cout << "Not jolly" << endl;
            return 0;
        }
    }
    cout << "Jolly" << endl;
    return 0;
}