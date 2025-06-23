#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int> a(n+1), b(n+1);
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> b[i];

        // 用来存所有操作
        vector<pair<int,int>> ops;
        ops.reserve(1600);

        // 1) 冒泡排序 a（操作类型 1）
        for(int pass = 1; pass < n; pass++){
            for(int i = 1; i < n; i++){
                if(a[i] > a[i+1]){
                    swap(a[i], a[i+1]);
                    ops.emplace_back(1, i);
                }
            }
        }
        // 2) 冒泡排序 b（操作类型 2）
        for(int pass = 1; pass < n; pass++){
            for(int i = 1; i < n; i++){
                if(b[i] > b[i+1]){
                    swap(b[i], b[i+1]);
                    ops.emplace_back(2, i);
                }
            }
        }
        // 3) 跨数组修正 a[i] < b[i]（操作类型 3）
        for(int i = 1; i <= n; i++){
            if(a[i] > b[i]){
                swap(a[i], b[i]);
                ops.emplace_back(3, i);
            }
        }

        // 输出
        cout << ops.size() << "\n";
        for(auto &op : ops){
            cout << op.first << " " << op.second << "\n";
        }
    }
    return 0;
}
