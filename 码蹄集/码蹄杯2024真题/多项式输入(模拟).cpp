#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    for(int i = n; i >= 0; i--)
    {
        int x;
        cin >> x;
        if(x != 0)
        {
            a.push_back({x, i});
        }
    }
    
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i].first > 0)
        {
            if(i) cout << "+";
            if(a[i].first != 1 || i + 1 == a.size()) cout << a[i].first;
        }
        else
        {
            if(a[i].first != -1) cout << a[i].first;
            else cout << "-";
        }
        if(a[i].second > 1) cout << "x^" << a[i].second;
        else if(a[i].second == 1) cout << "x";
    }
    return 0;
}