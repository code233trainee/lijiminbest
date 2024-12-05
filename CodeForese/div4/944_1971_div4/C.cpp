// #include <bits/stdc++.h>
// using namespace std;
// bool in(vector<int> v, int i)
// {
//     if(v.empty())
//     {
//         return false;
//     }
//     else
//     {
//         for(int j = 0; j < v.size(); j++)
//         {
//             if(i == v[j])
//             {
//                 return true;
//             }
//         }
//         return false;
//     }
// }
// void solve()
// {
//     int a, b, c, d;
//     cin >> a >> b >> c >> d;
//     if((a == c) || (a == d) || (b == c) || (b == d))
//     {
//         cout << "YES" << endl;
//         return;
//     }
//     vector<int> a1;
//     vector<int> b1;
//     int aa = a;
//     int bb = b;
//     while(b != (a+1))
//     {
//         a += 1;
//         if(a > 12)
//         {
//             a = 1;
//             a1.push_back(a);
//         }
//         else
//         {
//             a1.push_back(a);
//         }
//     }

//     while((bb+1) != aa)
//     {
//         bb += 1;
//         if(bb > 12)
//         {
//             bb = 1;
//             b1.push_back(bb);
//         }
//         else
//         {
//             b1.push_back(bb);
//         }
//     }
//     if((in(a1, c) && in(b1, d)) || (in(a1, d) && in(b1, c)))
//     {
//         cout << "YES\n";
//     }
//     else
//     {
//         cout << "NO\n";
//     }
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
//上面的代码让我感觉自己是小学生


//题解
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    string s;
    for(int i = 1; i <= 12; i++)
    {
        if(i == a || i == b)
        {
            s += 'a';
        }
        if(i == c || i == d)
        {
            s += 'b';
        }
    }
    cout << ((s == "abab" || s =="baba") ? "YES" : "NO") << endl;
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