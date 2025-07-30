#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    string s;
    cin >> s;
    set<int> pos;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '#')
        {
            pos.insert(i);
        }
    }
    if(pos.empty())
    {
        s[0] = 'o';
    }
    else
    {
        for(auto &ind : pos)
        {
            if(ind - 1 >= 0 && s[ind - 1] == '.')
            {
                s[ind - 1] = 'o';
            }
        }
        if(s[s.size() - 1] == '.')
        {
            s[s.size() - 1] = 'o';
        }
    }
    cout << s << endl;
    return 0;
}