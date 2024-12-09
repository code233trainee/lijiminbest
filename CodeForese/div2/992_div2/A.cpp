// #include <bits/stdc++.h>
// using namespace std;
// void solve()
// {
//     int n, k;
//     cin >> n >> k;
//     vector<int> a(n+1);
//     for(int i = 1; i <= n; i++)
//     {
//         cin >> a[i];
//     }
//     if(n == 1)
//     {
//         if(a[1]%k == 0)
//         {
//             cout << "YES\n";
//             cout << 1 << "\n";
//         }
//         else
//         {
//             cout << "YES\n";
//             cout << 1 << "\n";
//         }
//         return; 
//     }
//     // vector<int> cnt;
//     // cnt.push_back(0);
//     bool isok = false;
//     for(int i = 1; i <= n; i++)
//     {
//         isok = true;
//         for(int j = 1; j <= n; j++)
//         {
//             int diff = abs(a[i] - a[j]);
//             if(((i != j) && (diff % k == 0)))
//             {
//                 // cnt.push_back(a[i]);
//                 isok = false;
//                 break;
//             }
//         }
//         if(isok)
//         {
//             cout << "YES\n";
//             cout << i << "\n";
//             return;
//         }
//     }
//     cout << "NO\n"; 
// }
// int main()
// {
//     std::ios::sync_with_stdio(false);
// 	std::cin.tie(nullptr);
//     std::cout.tie(nullptr);
//     int t;
//     cin >> t;
//     while(t--)
//     {
//         solve();
//     }
//     return 0;
// }
// 元素只有一个的时候a必赢


//jiangly`s code
//(a-b)%k=0 <=> (a%k-b%k)%k = 0
//对于下面的实现来说，如果存在一个cnt[i]=1
//也就是说，如果存在一个数a没有与之配对的b，使|a-b|%k = 0;
//b就绝对无法找到一个数，然整个式子modk等于0;
#include <bits/stdc++.h>
void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n), cnt(k);
    for(int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        a[i] %= k;
        cnt[a[i]]++;
    }
    for(int i = 0; i < n; i++)
    {
        if(cnt[a[i]] == 1)
        {
            std::cout << 1;
            std::cout << i + 1 << "\n";
            return;
        }
    }
    std::cout << "NO\n";
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}

