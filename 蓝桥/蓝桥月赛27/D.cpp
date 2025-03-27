#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
typedef long long ll;
 
// 树状数组（Fenwick Tree）实现
struct Fenwick {
    int n;
    vector<int> fenw;
    Fenwick(int n): n(n), fenw(n+1, 0) {}
    
    // 更新下标 i（1-indexed）的值，delta为变化量
    void update(int i, int delta) {
        for (; i <= n; i += i & -i)
            fenw[i] += delta;
    }
    
    // 查询前 i 个位置的累计和
    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i)
            sum += fenw[i];
        return sum;
    }
};
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> B[i];
    
    // 蓝队队员按照拳头大小排序
    vector<int> blue = A;
    sort(blue.begin(), blue.end());
    
    // 离散化所有拳头数值（蓝队和红队的）
    vector<int> vals;
    for (int x : A) vals.push_back(x);
    for (int x : B) vals.push_back(x);
    sort(vals.begin(), vals.end());
    //去除重复的元素
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    
    auto getIndex = [&](int x) {
        return (int)(lower_bound(vals.begin(), vals.end(), x) - vals.begin()) + 1; // 1-indexed
    };
    
    // 树状数组大小为离散化后的数值个数
    Fenwick fenw(vals.size());
    
    ll result = 0;
    // 模拟比赛的 N 轮：每轮先更新红队数据，再查询蓝队的胜利次数
    for (int i = 0; i < N; i++){
        // 红队第 i 轮出场，更新红队队员的拳头大小
        int idxB = getIndex(B[i]);
        fenw.update(idxB, 1);
        
        // 蓝队按照排序顺序安排队员出场，第 i 轮出场的拳头为 blue[i]
        int idxBlue = getIndex(blue[i]);
        // 查询红队中有多少人拳头值小于 blue[i]
        int wins = fenw.query(idxBlue - 1);
        result += wins;
    }
    
    cout << result << "\n";
    return 0;
}
