// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// struct ty{
//     ll m;
//     ll c;
//     char name;
// };
// bool cmp(ty a, ty b)
// {
//     return a.m > b.m;
// }
// int main()
// {
//     ll n;
//     cin >> n;
//     ll l, q;
//     l = n/2;
//     q = n - n/2;
//     vector<ty> lis;
//     for(int i = 0; i < n; i++)
//     {
//         ll a, b;
//         cin >> a >> b;
//         lis.push_back({a, i+1, 'l'});
//         lis.push_back({b, i+1, 'q'});
//     }
//     sort(lis.begin(), lis.end(), cmp);
//     ll ans = 0;
//     vector<bool> c(n+1);
//     for(int i = 0; i < 2 * n; i++)
//     {
//         if(lis[i].name == 'l' && c[lis[i].c] == false && l > 0)
//         {
//             ans += lis[i].m;
//             c[lis[i].c] = true;
//             l--;
//         }
//         if(lis[i].name == 'q' && c[lis[i].c] == false && q > 0)
//         {
//             ans += lis[i].m;
//             c[lis[i].c] = true;
//             q--;
//         }
//     }
//     cout << ans;
//     return 0;
// }
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    // 读取每个班级的小蓝和小桥的酬劳
    vector<long long> A(n), B(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i]; // 注意：如果输入格式为每行两个数
    }

    // 计算基数：全部班级小桥获得的酬劳总和
    long long base = 0;
    for (int i = 0; i < n; i++) {
        base += B[i];
    }
    
    // 计算每个班级让小蓝去后额外增加的收益
    vector<long long> diff(n);
    for (int i = 0; i < n; i++) {
        diff[i] = A[i] - B[i];
    }
    
    // 对 diff 进行降序排序
    sort(diff.begin(), diff.end(), greater<long long>());
    
    // 小蓝必须去 floor(n/2) 个班级
    int k = n / 2;
    long long extra = 0;
    for (int i = 0; i < k; i++) {
        extra += diff[i];
    }
    
    // 总酬劳为基数加上小蓝额外收益
    long long ans = base + extra;
    cout << ans << "\n";
    
    return 0;
}
