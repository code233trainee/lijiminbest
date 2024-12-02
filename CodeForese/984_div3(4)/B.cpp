// #include  <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     //高效处理输入输出
//     ios::sync_with_stdio(false);
// 	cin.tie(nullptr);

//     int t = 0;
//     cin >> t;
//     while(t--)
//     {
//         int n, k;
//         cin >> n >> k;
//         map<int, int> m;//map储存是键值对，set储存的是键
//         for(int i = 0; i < k; i++)
//         {
//             int a, b;
//             cin >> a >> b;
//             if(m.count(a))
//             {
//                 m[a] += b;
//             }
//             else
//             {
//                 m[a] = b;
//             }
//         }
//         int ans = 0;
//         int s = m.size();
//         if((s - n) > 0)
//         {
//             while(n--)
//             {
//                 int maxNum = INT_MIN;
//                 int key = 0;
//                 for(const auto& enty : m)
//                 {
//                     if(enty.second > maxNum)
//                     {
//                         maxNum = enty.second;
//                         key = enty.first;
//                     }
                    
//                 }
//                 if(m.count(key))
//                 {
//                     m.erase(key);
//                 }
//                 ans += maxNum;
//             }
//         }
//         else
//         {
//             while(s--)
//             {
//                 int maxNum = INT_MIN;
//                 int key = 0;
//                 for(const auto& enty : m)
//                 {
//                     maxNum = enty.second;
//                     key = enty.first;
//                 }
//                 if(m.count(key))
//                 {
//                     m.erase(key);
//                 }
//                 ans += maxNum;
//             }
//         }
        
//         cout << ans << endl;
//     }
// }

//以上代码会超时

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    n = min(n, k);
    vector<int> v(k);
    for(int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        v[a] += b;
    }
    sort(v.begin(), v.end(), std::greater<int>());
    //accumulate函数定义累加，前两个函数接受范围，第三个参数定义累加的初始值
    int ans = accumulate(v.begin(), v.begin() + n, 0);
    cout << ans << endl;
}

int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}