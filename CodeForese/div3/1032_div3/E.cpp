#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        string L, R;
        cin >> L >> R;
        int n = L.size();

        // dp[i][tL][tR]：从第 i 位到末尾的最小花费
        static int dp[12][2][2];
        // 末尾基准
        for(int tL=0; tL<2; tL++)
            for(int tR=0; tR<2; tR++)
                dp[n][tL][tR] = 0;

        // 从后往前算
        for(int i = n-1; i >= 0; i--){
            for(int tL = 0; tL < 2; tL++){
                for(int tR = 0; tR < 2; tR++){
                    int &res = dp[i][tL][tR];
                    res = INF;
                    int lo = tL ? (L[i]-'0') : 0;
                    int hi = tR ? (R[i]-'0') : 9;
                    for(int d = lo; d <= hi; d++){
                        int cost = (d == L[i]-'0') + (d == R[i]-'0');
                        int ntL  = tL && (d == L[i]-'0');
                        int ntR  = tR && (d == R[i]-'0');
                        res = min(res, cost + dp[i+1][ntL][ntR]);
                    }
                }
            }
        }

        // 最终答案：从 0 位开始，且同时紧贴 L 与 R
        cout << dp[0][1][1] << "\n";
    }
    return 0;
}
