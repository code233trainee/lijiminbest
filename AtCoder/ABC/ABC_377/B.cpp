#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<string> s(9);
    for(int i = 1; i <= 8; i++)
    {
        string ss;
        cin >> ss;
        s[i] = " " + ss;
    }
    set<int> c;
    set<int> r;
    for(int i = 1; i < 9; i++)
    {
        for(int j = 1; j < 9; j++)
        {
            if(s[i][j] == '#')
            {
                c.insert(j);
                r.insert(i);
            }
        }
    }
    int row = 8 - r.size();
    int column = 8 - c.size();
    int ans = row * column;
    cout << ans << endl;
}