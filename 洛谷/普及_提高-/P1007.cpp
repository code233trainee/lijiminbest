#include <bits/stdc++.h>
using namespace std;
int main()
{
    int l, n;
    cin >> l >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if(!n)
    {
        cout << "0 0" << endl;
        return 0;
    }
    int mindis = INT_MIN;
    int maxdis = INT_MIN;
    sort(a.begin()+1, a.end());
    for(int i = 1; i <= n; i++)
    {
        mindis = max(min(l + 1 - a[i], a[i]), mindis);
    }
    maxdis = max(l + 1 - a[1], a[n]);

    cout << mindis << " " << maxdis << endl;
    return 0;
}