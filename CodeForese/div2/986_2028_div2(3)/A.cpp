// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     //高效处理输入输出
//     ios::sync_with_stdio(false);
// 	cin.tie(nullptr);
    
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         int n ,x, y;
//         cin >> n >> x >> y;
//         string s;
//         cin >> s;
//         int x0 = 0, y0 = 0;
//         int j = 20;
//         bool b = false;
//         while(j--)
//         {
            
//             for(int i = 0; i < n; i++)
//             {
//                 if(s[i] == 'N')
//                 {
//                     y0++;
//                     if(x0 == x && y0 == y) 
//                     {
//                         b = true;
//                         break;
//                     }
//                 }
//                 else if(s[i] == 'E')
//                 {
//                     x0++;
//                     if(x0 == x && y0 == y) 
//                     {
//                         b = true;
//                         break;
//                     }
//                 }
//                 else if(s[i] == 'S')
//                 {
//                     y0--;
//                     if(x0 == x && y0 == y) 
//                     {
//                         b = true;
//                         break;
//                     }
//                 }
//                 else
//                 {
//                     x0--;
//                     if(x0 == x && y0 == y) 
//                     {
//                         b = true;
//                         break;
//                     }
//                 }
//             }
//             if(b)
//             {
//                 break;
//             }
//         }
//         if(b)
//         {
//             cout << "YES" << endl;
//         }
//         else
//         {
//             cout << "NO" << endl;
//         }
//     }
// }

//以上代码循环太小，但是能AC
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int a, x, y;
        cin >> a >> x >> y;
        string s;
        cin >> s;
        int x1 = 0, y1 = 0;
        for(int i = 0; i < 1000; i++)
        {
            //模字符串长度就不会溢出了，可以循环很多次
            if(s[i%a] == 'N')y1++;
            else if(s[i%a] == 'S')y1--;
            else if(s[i%a] == 'E')x1++;
            else x1--;
            if(x1==x && y1 == y)
            {
                cout << "YES" << endl;
                return;
            }
        }
        cout << "NO" << endl;
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