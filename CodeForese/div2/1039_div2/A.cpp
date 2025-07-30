
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
        ll c;
        cin >> n >> c;
        vector<ll> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        vector<int> deadline(n);
        for(int i = 0; i < n; i++){
            if(a[i] > c){
                // 绝对必花钱
                deadline[i] = 0;
            } else {
                // k = floor(log2(c / a[i]))
                ll ratio = c / a[i];
                int k = 0;
                // ratio >= 1 保证至少 k=0
                // bit_length - 1 就是 floor(log2(ratio))
                k = 63 - __builtin_clzll(ratio);
                // 可无偿销毁的最晚时刻为 k (0-based)
                // 在 Moore 算法里用 D = k+1（1-based 时隙）
                deadline[i] = k + 1;
            }
        }

        sort(deadline.begin(), deadline.end());
        int t = 0;  // 已安排的“无偿销毁”数量
        for(int D : deadline){
            if(t + 1 <= D){
                // 可以按时销毁
                t++;
            }
            // 否则跳过，算作迟到（需要花钱）
        }

        // 需要付费的个数 = n - 能无偿销毁的个数
        cout << (n - t) << "\n";
    }

    return 0;
}
