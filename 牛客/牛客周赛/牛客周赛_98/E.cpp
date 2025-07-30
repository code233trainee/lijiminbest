#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    int M = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        M = max(M, a[i]);
    }
    
    vector<ll> sumval(M+1, 0);
    for(int x : a){
        sumval[x] += x;
    }

    ll answer = 0;
    vector<ll> S(M+1, 0);
    vector<int> G(M+1, 0);

    // 对每个可能的 d 枚举它的所有倍数 k
    for(int d = 1; d <= M; d++){
        ll sum_d = 0;
        int g = 0;
        for(int k = d; k <= M; k += d){
            if(sumval[k] > 0){
                sum_d += sumval[k];
                g = gcd(g, k);
            }
        }
        // 如果这些 k 的 gcd 恰好是 d，自然可以把它们全选进来
        if(g == d){
            answer = max(answer, sum_d * d);
        }
    }

    cout << answer << "\n";
    return 0;
}
