#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
    int n, d;
    cin >> n >> d;
    vector<int> result;
    result.push_back(1);
    if(n * d % 3 == 0)
    {
        result.push_back(3);
    }
    if(d % 5 == 0)
    {
        result.push_back(5);
    }
    
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