// #include <bits/stdc++.h>
// using namespace std;
// void solve()
// {
//     int n;
//     cin >> n;
//     vector<int> v(n);
//     for(int i = 0; i < n; i++)
//     {
//         cin >> v[i];
//     }
//     int a = 0, b = 0;
//     bool isfind = false;
//     for(int i = 0; i < n; i++)
//     {
//         a = v[i];
//         for(int j = i + 1; j < n; j++)
//         {
//             if( a > n-2)
//             {
//                 break;
//             }
//             else
//             {
//                 if(a * v[j] == n - 2)
//                 {
//                     b = v[j];
//                     isfind = true;
//                     break;
//                 }
//             }
//         }
//         if(isfind)
//         {
//             break;
//         }
//     }
//     cout << a << " " << b << endl;
// }
// int main()
// {
//     int t;
//     cin >> t;
//     while(t--)
//     {
//         solve();
//     }
// }
// 以上会超时


// #include <bits/stdc++.h>
// #include <unordered_set>
// using namespace std;

// void solve() {
//     int n;
//     cin >> n;
//     vector<int> v(n);
//     unordered_set<int> seen; // 哈希表用于快速查找

//     for (int i = 0; i < n; i++) {
//         cin >> v[i];
//     }

//     int a = -1, b = -1;
//     for (int i = 0; i < n; i++) {
//         int target = n - 2; // 目标值
//         if (v[i] > 0 && target % v[i] == 0) {
//             int complement = target / v[i];
//             if (seen.count(complement)) {
//                 a = v[i];
//                 b = complement;
//                 break;
//             }
//         }
//         seen.insert(v[i]);
//     }

    
//     cout << a << " " << b << endl;
    
// }
 
// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
    
//     int t;
//     cin >> t;
//     while (t--) {
//         solve();
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int val = n - 2;
    vector<int> a(n);
    for(auto & z : a)
    {
        cin >> z;
    }
    map<int, int> c;
    for(int i = 0; i < n; i++)
    {
        //要求两个数x, y相乘是不是等于val
        if(val%a[i] == 0 && c[val/a[i]])//只要当前的因数，和另一个因数(val/a[i])都出现
        {
            cout << a[i] << " " << val/a[i] << endl;
            return;
        }
        c[a[i]]++;
    }
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
