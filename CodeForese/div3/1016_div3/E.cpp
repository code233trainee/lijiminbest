#include <iostream>
#include <vector>
using namespace std;
 
typedef long long ll;
 
// 判断 candidate x 是否可以划分成至少 k 个子数组，且每个子数组包含 0,1,...,x-1
bool canPartition(const vector<int>& a, int k, int x) {
    int n = a.size();
    // x==0时，要求为空集，始终满足
    if(x == 0) return true;
    
    // 必要性检查：整个数组中每个数字 t in [0, x-1] 至少出现 k 次
    vector<int> totalFreq(x, 0);
    for (int i = 0; i < n; i++) {
        if(a[i] < x)
            totalFreq[a[i]]++;
    }
    for (int t = 0; t < x; t++) {
        if(totalFreq[t] < k)
            return false;
    }
    
    // 贪心划分：从左到右扫描，找出尽可能多的段，每段必须包含 [0, x-1]
    int segments = 0;
    vector<int> seen(x, 0);
    int missing = x;  // 当前段还缺少 missing 个数字
    for (int i = 0; i < n; i++) {
        int val = a[i];
        if(val < x) {
            // 如果第一次在当前段中遇到这个数字，则 missing 减1
            if(seen[val] == 0) {
                missing--;
            }
            seen[val]++;
        }
        // 当前段包含了所有 0...x-1
        if(missing == 0) {
            segments++;
            // 如果已经分得足够段数则返回 true
            if(segments >= k)
                return true;
            // 重置当前段，开始下一段
            seen.assign(x, 0);
            missing = x;
        }
    }
    return false;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
 
        // 二分查找答案 x，x 的范围在 [0, n+1)
        int lo = 0, hi = n + 1;  // hi 取 n+1 表示不可能达到的上界
        while(lo + 1 < hi){
            int mid = lo + (hi - lo) / 2;
            if(canPartition(a, k, mid))
                lo = mid;  // mid 可行，尝试更大值
            else
                hi = mid;  // mid 不可行
        }
        cout << lo << "\n";
    }
 
    return 0;
}
