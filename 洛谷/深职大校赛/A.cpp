#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    string s;
    cin >> s;
    int k = 0;
    cin >> k;
    int cnt = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '6')
        {
            cnt++;
        }
    }
    cout << (cnt == k ? "YES" : "NO") << endl;
    return 0;
}