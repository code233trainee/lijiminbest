#include <bits/stdc++.h>

void solve()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<int> b(55);
    for(int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        b[a[i]]++;
    }
    for(int i = 0; i < 55; i++)
    {
        if(b[i]&1)
        {
            std::cout << "YES\n";
            return;
        }
        //只要前面是偶数A就不会赢
        //只要后面出现了一个奇数个的数字，A就可以选择这个数字，
        //这样无论B选什么A都有数字可选
    }
    std::cout << "NO\n";
    return;
}
int main()
{
    int t;
    std::cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}


// //tourist`s code
// //看不太懂
// #include <bits/stdc++.h>
// int main()
// {
//     int t;
//     std::cin >> t;
//     while(t--)
//     {
//         int n;
//         std::cin >> n;
//         std::vector<int> a(n);
//         for(int i = 0; i < n; i++)
//         {
//             std::cin >> a[i];
//         }
//         std::sort(a.begin(), a.end());
//         //逆向思维来看
//         //如果b能稳赢的情况
//         bool win = true;
//         for(int i = 0; i < n; i+=2)
//         {
//             //
//             if(i == n - 1 || a[i] != a[i + 1])
//             {
//                 win = false;
//                 break;
//             }
//         }
//         std::cout << (win ? "NO" : "YES") << "\n";
//     }
//     return 0;
// }