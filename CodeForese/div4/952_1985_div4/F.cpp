// #include <bits/stdc++.h>
// using namespace std;
// bool cmp(const pair<int, int> &a, const pair<int, int> &b)
// {
//     //降序排序
//     return a.first >= b.first;
// }

// bool cmp1(const pair<int, int> &a, const pair<int, int> &b)
// {
//     //升序，如果不使用这个函数，first相同会比较second
//     return a.first <= b.first;
// }
// void solve()
// {
//     int h, n;
//     cin >> h >> n;
//     vector<pair<int, int>> v0(n);
//     vector<pair<int, int>> v1(n);
//     for(int i = 0; i < n; i++)
//     {
//         cin >> v0[i].first;
//         v1[i].second = v0[i].first;
//     }
//     for(int i = 0; i < n; i++)
//     {
//         cin >> v0[i].second;
//         v1[i].first = v0[i].second;
//     }
//     sort(v0.begin(), v0.end(), cmp);
//     sort(v1.begin(), v1.end(), cmp1);//默认升序
    
//     long long num = 1;
//     for(int i = 0; i < n; i++)
//     {
//         h -= v0[i].first;
//         if(h <= 0)
//         {
//             cout << num << endl;
//             return;
//         }   
//     }
//     num += v1[0].first;
//     int occu;
//     int last = v1[0].second;
//     int i = -1;
//     while(h > 0)
//     {
//         occu = v1[++i%n].second;
//         if(occu == last)
//         {
//             h -= v1[i%n].second;
//             if(h <= 0)
//             {
//                 cout << num << endl;
//                 return;
//             }
//         }
//         else
//         {
//             last = occu;
//             int temp = v1[i%n].first - v1[(i-1)%n].first;
//             if(temp < 0)
//             {
//                 temp = -temp + 1;
//             }
//             num += temp;
//             h -= v1[i%n].second;
//             if(h <= 0)
//             {
//                 cout << num << endl;
//                 return;
//             }
//         }
        
//     }
    
// }
// int main()
// {
//     std::ios::sync_with_stdio(false);
// 	std::cin.tie(nullptr);

//     int t;
//     cin >> t;
//     while(t--)
//     {
//         solve();
//     }
// }
// 以上代码调了半天没调对
// 但是复习到了自定义sort的排序方式

#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int h, n;
    cin >> h >> n;
    vector<int> a(n), c(n);
    for(auto &i : a)
    {
        cin >> i;
    }
    for(auto &i : c)
    {
        cin >> i;
    }
    set<pair<long long, int>> s;
    for(int i = 0; i < n; i++)
    {
        s.insert({1, i});//按照字典序升序(第一个元素相同再比较第二个元素)
        //第一次每次都是第一回合
    }
    long long last_turn = 1;
    while(h > 0)
    {
        auto [turn, i] = *s.begin();//赋值给turn, i,目前都是第一回合
        s.erase(s.begin());
        last_turn = turn;
        h -= a[i];
        s.insert({turn + c[i], i});//下次遇到会直接快进到这个回合
    }
    cout << last_turn << "\n";
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}