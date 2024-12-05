#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> ch(26);
    for(auto c : s)
    {
        ch[c - 'a']++;
    }
    int min = -1;
    int max = -1;
    for(int i = 0; i < 26; i++)
    {
        if(ch[i])
        {
            if(min == -1 || ch[min] > ch[i]) min = i;
            if(max == -1 || ch[max] <= ch[i]) max = i;    
        }
        
    }
    for(auto &z : s)
    {
        if(z == min + 'a')
        {
            z = max + 'a';
            break;
        }
    }
    cout << s << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}