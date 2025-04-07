#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> u;
    vector<int> v;
    vector<int> degree(200005);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        degree[a]++;
        degree[b]++;
    }
    if(m < 1)
    {
        cout << 0 << "\n";
        return 0;
    }

    return 0;
}