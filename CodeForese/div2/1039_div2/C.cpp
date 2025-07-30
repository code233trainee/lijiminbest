#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    auto work = [&]() -> bool {
        int mn = a[0];
        for(int i = 0; i < n; i++)
        {
            if(a[i] >= mn * 2)
            {
                return false;
            }
            mn = min(a[i], mn);
        }
        return true;
    };
    cout << (work() ? "YES" : "NO") << endl;
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
