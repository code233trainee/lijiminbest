#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        ll n;
        cin >> n;
        vector<pair<ll,ll>> c(3);
        for(int i = 0; i < 3; i++){
            cin >> c[i].first >> c[i].second;
        }

        ll ans = n;
        for(int mask = 0; mask < (1<<3); mask++){
            vector<int> idx;
            for(int i = 0; i < 3; i++){
                if(mask & (1<<i)) idx.push_back(i);
            }
            sort(idx.begin(), idx.end());
            do {
                ll cur = n;
                for(int j : idx){
                    ll a = c[j].first, b = c[j].second;
                    if(cur >= a){
                        cur = max(0LL, cur - b);
                    }
                }
                ans = min(ans, cur);
            } while(next_permutation(idx.begin(), idx.end()));
            // 生成下一个排列
        }

        cout << ans << "\n";
    }

    return 0;
}
