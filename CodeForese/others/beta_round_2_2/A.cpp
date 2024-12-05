#include <bits/stdc++.h>
using namespace std;
int max = INT_MIN;
int main()
{
    int n = 0;
    cin >> n;
    map<string, int> m;
    for(int i = 0; i < n; i++)
    {
        int sorc = 0;
        string s;
        cin >> s >> sorc;
        m[s] += sorc;
    }
}