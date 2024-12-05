// #include <bits/stdc++.h>
// using namespace std;
// //并查集
// void solve()
// {
//     int n = 0;
//     cin >> n;
//     vector<int> a(n);
//     for(int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     int l = -1;
//     int simpE = 0;
//     int judge = 0;
//     int ans = 0;
//     for(int r = 0; r < n; r++)
//     {
//         if(r == 0 && a[r] != 0)
//         {
//             simpE += a[r];
//             judge = simpE;
//         }
//         else
//         {
//             simpE += a[r];
//             if(judge == simpE)
//             {
//                 ans++;
//                 r++;
//                 simpE += a[r];
//                 judge = simpE;
//             } 
//         }
//         if(r == n - 1 && a[r] == 0)
//         {
//             ans++;
//         }
//     }
//     cout << ans << endl;
// }

// int main()
// {
//     //高效处理输入输出
//     ios::sync_with_stdio(false);
// 	cin.tie(nullptr);

//     int t = 0;
//     cin >> t;
//     while(t--)
//     {
//         solve();
//     }
// }

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n = 0; cin >> n;
    long long int cur = 0;
    int ans = 0;
    set<long long int> s {0};//注意数据范围
    while(n--)
    {
        int a = 0;
        cin >> a;
        cur += a;
        if(s.count(cur))
        {
            ans++;
            cur = 0;
            s.clear();
        }
        s.emplace(cur);
    }
    cout << ans << "\n";
}

int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        solve();
    }
}