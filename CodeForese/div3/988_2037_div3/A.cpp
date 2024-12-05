#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    map<int, int> m;
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        m[num]++;
    }
    int duplicates = 0;
    for (auto &entry : m) {
        if (entry.second > 1) {  
            duplicates += entry.second/2;
        }
    }
    cout << duplicates << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}