#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    set<int> s;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    cout << s.size() << endl;
    for(auto &z : s)
    {
        cout << z << " ";
    }
    
    return 0;
}