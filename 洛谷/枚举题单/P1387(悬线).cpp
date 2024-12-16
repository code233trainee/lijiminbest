// #include <bits/stdc++.h>
// int main()
// {
//     int n, m;
//     std::cin >> n >> m;
//     std::vector<std::vector<int>> a(n, std::vector<int>(m));
//     for(int i = 0; i < n; i++)
//     {
//         for(int j = 0; j < m; j++)
//         {
//             std::cin >> a[i][j];
//         }
//     }
//     int mx = 0;
    
//     auto check = [&](int i, int j)->void{
//         int k = 0;
//         while(1)
//         {
//             if( i + k < n && j + k < m)
//             {
//                 for(int p = 0; p <= k; p++)
//                 {
//                     for(int g = 0; g <= k; g++)
//                     {
//                         if(a[p][g] == 1 && a[p][g] == 1 && a[i+k][j+k] == 1)
//                     }
//                 }
//                 if(a[i+k][j] == 1 && a[i][j+k] == 1 && a[i+k][j+k] == 1)
//                 {
//                     if(k+1 > mx)
//                     {
//                         mx = k+1;
//                     }
//                     k++;
//                 }
//                 else
//                 {
//                     break;
//                 }
//             }
//             else
//             {
//                 break;
//             }
//         }
//     };
//     for(int i = 0; i < n; i++)
//     {
//         for(int j = 0; j < m; j++)
//         {
//             if(a[i][j] == 1)
//             {
//                 check(i, j);
//             }
//         }
//     }
//     std::cout << mx << "\n";
//     return 0;
// }
//以上判断不全面

// #include<cstdio>
// int n,m,ans=1,a[1010][1010];
// bool pd(int a1,int b,int c,int d)
// {
//     for(int i=a1;i<=b;i++)
//     {
//         for(int j=c;j<=d;j++)
//         {
//             if(a[i][j]==0)
//             {
//                 return false;
//             } 
//         }
            
//     }
//     return true;
// }
// int main()
// {
//     scanf("%d %d",&n,&m);
//     for(int i=1;i<=n;i++)
//         for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
//     for(int i=1;i<=n;i++)
//         for(int j=1;j<=m;j++)
//             if(a[i][j]==1)
//             {
//                 int k=1,h=i+1,l=j+1;
                
//                 while(pd(i,h,j,l)) { h++; l++; k++; }
//                 if(k>ans) ans=k;
//             }
//     printf("%d",ans);
//     return 0;
// }


//悬线法
#include <bits/stdc++.h>
using namespace std;
int a[110], l[110], r[110], n, m, ans;
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            l[j] = r[j] = j;
        }
        for(int j = 1; j <= m; j++)
        {
            char c;
            cin >> c;
            if(c == '0')
            {
                a[j] = 0;
            }
            else
            {
                a[j]++;
            }
        }
        for(int j = 1; j <= m; j++)
        {
            while(l[j] != 1 && a[l[j] - 1] >= a[j])
            {
                l[j] = l[l[j] - 1];
            }
        }
        for(int j = m; j >= 1; j--)
        {
            while(r[j] != m && a[r[j] + 1] >= a[j])
            {
                r[j] = r[r[j] + 1];
            }
        }
        for(int j = 1; j <= m; j++)
        {
            if((r[j] - l[j] + 1) >= a[j])
            {
                ans = max(ans, a[j]);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
