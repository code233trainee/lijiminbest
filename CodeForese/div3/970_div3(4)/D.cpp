// #include <bits/stdc++.h>
// using namespace std;

// void solve()
// {
//     int n;
//     cin >> n;
//     vector<int> vec(n);
//     for(int i = 0; i < n; i++)
//     {
//         cin >> vec[i];
//     }
//     string s;
//     cin >> s;
//     for(int i = 0; i < n; i++)
//     {
//         int ans = 0;
//         int j = vec[i] - 1;
//         while( vec[i] != vec[j])
//         {
//             if(s[j] == '0')
//             {
//                 ans++;
//                 j = vec[j] - 1;
//             }
//             else
//             {
//                 j = vec[j] - 1;
//             }
//         }
//         if(s[i] == '0')
//         {
//             ans++;
//         }
//         cout << ans << " ";
//     }
//     cout << endl;
// }
// int main()
// {
//     //高效处理输入输出
//     ios::sync_with_stdio(false);
// 	cin.tie(nullptr);

//     int t;
//     cin >> t;
//     while(t--)
//     {
//         solve();
//     }
// }
//以上会超时

#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        vector<long long> p(n+1),b(n+1);
        vector<int> us(n+1);
        for(int i=1;i<=n;i++)
        {
            cin>>p[i];
        }
        string s;
        cin >> s;
        for(int i=1;i<=n;i++)//实际上每个元素的访问是循环的，比如3 5 6 1 2 4，对于3，属于它的循环是3，6，4，1，3，
        {                     //未来遇到6，4，1实际上是同一套循环，就不需要再次遍历了
            if(us[i])continue;
            int sz=0;
            while(!us[i])
            {
                us[i]=1;
                sz += s[i - 1] == '0';
                i=p[i];
            }
            while(us[i]!=2)//把结果存入数组b
            {
                b[i]=sz;
                us[i]=2;
                i=p[i];
            }
        }
        for(int i=1;i<=n;i++)
        {
            cout<<b[i]<<" ";
        }
        cout<<endl;
    }
}