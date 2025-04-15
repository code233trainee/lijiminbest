#include <bits/stdc++.h>
using namespace std;
string s;
void solve()
{
    cin >> s;
    int n = s.size();
    vector<int> a;
    for(int i = 0; i < n; i++)
    {
        if(s[i] != 'l' && s[i] != 'q' && s[i] != 'b')
        {
            a.push_back(i);
        }
    }
    if(a.size() == 0)
    {
        cout << "Yes" << endl;
        return;
    }
    int left = a[0], right = a[a.size()-1], l = a[0], r = a[a.size()-1];
    while(left <= right && s[left] == s[right])
    {
        left++;
        right--;
    }
    while(l >= 0 && r < n && s[l] == s[r])
    {
        l--;
        r++;
    }
    cout << ((left > right) && (l < 0) ? "Yes" : "No") << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}