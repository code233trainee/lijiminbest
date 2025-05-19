#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<int> b(n+1);
    for(int i = 1; i <= n; i++)
    {
        b[i] = abs(a[i]);
    }
    int mask = b[1];
    sort(b.begin()+1, b.end());
    int ind = lower_bound(b.begin()+1, b.end(), mask) - b.begin();
    if(ind <= (n)/2 + 1)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
