#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll K;
    cin >> N >> K;
    vector<ll> v(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }

    // 1. 从大到小排序
    sort(v.begin(), v.end(), greater<ll>());

    // 2. 贪心分组
    ll ans = 0;   // 成功击败大魔王的队伍数
    ll cnt = 0;   // 当前正在凑成一支队伍的人数
    for(int i = 0; i < N; i++){
        cnt++;
        // 如果以 v[i]（当前最弱）为队伍最小能力，
        // cnt * v[i] >= K 则可以成队
        if (cnt * v[i] >= K) {
            ans++;
            cnt = 0;  // 重置，开始下一支队伍
        }
    }

    cout << ans << "\n";
    return 0;
}
