#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.length();
    vector<string> a(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < i + n; j++)
        {
            a[i] += s[j%n];
        }
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++)
    {
        cout << a[0][i];
    }
    return 0;
}