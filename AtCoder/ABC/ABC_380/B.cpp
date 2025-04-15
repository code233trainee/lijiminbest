#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    vector<int> v;
    int ans = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '|')
        {
            v.push_back(i);
        }
    }
    for(int i = 1; i < v.size(); i++)
    {
        cout << v[i] - v[i-1] - 1 << " ";
    }
}