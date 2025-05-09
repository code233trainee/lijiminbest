#include <bits/stdc++.h>
using namespace std;
bool cmp(string a, string b)
{
    //注意字符串的比较
    // 2 221 与 221 2
    return a + b > b + a;
}
int main()
{
    int n;
    cin >> n;
    vector<string> a(n);
    string s = "";
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), cmp);
    for(int i = 0; i < n; i++)
    {
        cout << a[i];
    }
    return 0;
}