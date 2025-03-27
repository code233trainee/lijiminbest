#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    vector<int> a(14);
    for(int i = 0; i < 7; i++)
    {
        int b;
        cin >> b;
        a[b]++;
    }
    sort(a.begin(), a.end(), cmp);
    if(a[0] >= 3 && a[1] >= 2)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}