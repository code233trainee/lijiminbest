#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    
    int n = s.size();
    int sum = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        int v = s[i] - '0';
        int u = ((i < n - 1) ? (s[i + 1] - '0') : 0);
        int d = (10 + v - u) % 10;
        sum += d;
    }
    sum += n;
    cout << sum << endl;
    return 0;
}