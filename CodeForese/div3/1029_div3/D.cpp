#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
void solve()
{
    // int n;
    // cin >> n;
    // vector<int64> a(n+1);
    // for(int i=1;i<=n;i++) cin >> a[i];
    // int64 num = n * a[1] - a[n];
    // int64 den = 1LL * n * n - 1;
    // if(num < 0 || num % den != 0){
    //     cout << "NO\n";
    //     return;
    // }
    // int64 y = num / den;
    // int64 x = a[1] - n * y;
    // if(x < 0){
    //     cout << "NO\n";
    //     return;
    // }
    // bool ok = true;
    // for(int i=1;i<=n;i++){
    //     if(a[i] != x * i + y * (n - i + 1)){
    //         ok = false;
    //         break;
    //     }
    // }
    // cout << (ok ? "YES\n" : "NO\n");
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    auto check = [&]() ->bool{
        if(a[1] < 0) return false;
        if(a[1] % (n+1)) return false;
        for(int i = 1; i <= n; i++)
        {
            if(a[i] != a[1])
            {
                return false;
            }
        }
        return true;
    };
    bool ok = true;
    if(a[1] == a[2])
    {
        ok = check();
    }
    else if(a[1] > a[2])
    {
        int k = a[1] - a[2];
        for(int i = 1; i <= n; i++)
        {
            a[i] -= (n-i+1) * k;
        }
        ok = check();
    }
    else
    {
        int k = a[2] - a[1];
        for(int i = 1; i <= n; i++)
        {
            a[i] -= i * k;
        }
        ok = check();
    }
    cout << (ok ? "YES" : "NO") << "\n";
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
