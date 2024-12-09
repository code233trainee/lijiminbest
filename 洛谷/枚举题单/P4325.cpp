#include <bits/stdc++.h>
using namespace std;
int main()
{
    set<int> se;
    for(int i = 0; i < 10; i++)
    {
        int n;
        cin >> n;
        se.insert(n%42);
    }
    cout << se.size() << endl;
    return 0;
}