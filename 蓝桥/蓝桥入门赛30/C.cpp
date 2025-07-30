#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll M;
    cin >> N >> M;
    vector<ll> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    // 去重并排序
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    int K = A.size();
    if(K == 1){
        cout << 0 << "\n";
        return 0;
    }
    // 计算各间隔并找最大值
    ll max_gap = 0;
    for(int i = 0; i + 1 < K; i++){
        max_gap = max(max_gap, A[i+1] - A[i]);
    }
    // 环上首尾间隔
    max_gap = max(max_gap, A[0] + M - A[K-1]);

    // 答案 = 环长减去最大空段
    cout << (M - max_gap) << "\n";
    return 0;
}
