#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> a(200);
    a[1] = 1;
    a[2] = 0;
    for(int i = 3; i <= 100; i++)
    {
        a[i] = a[i-2];
    } 
    int l, r;
    cin >> l >> r;
    set<int> s;
    for(; l <= r; l++)
    {
        s.insert(a[l]);
    }
    cout << s.size() << endl;
    return 0;
}