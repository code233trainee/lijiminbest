#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int> p(n+1);
        for(int i = 1; i <= n; i++){
            cin >> p[i];
        }

        ll ans = (ll)n * (n + 1) / 2;

        for(int i = 1; i < n; i++){
            if(p[i] > p[i+1]){
                ans += (ll)i * (n - i);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
