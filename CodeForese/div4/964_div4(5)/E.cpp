#include <iostream>
// #include <bits/stdc++.h>
using namespace std;
const int MAX = 200005;
int a[MAX], num[MAX];
int Etimes (int k)
{
    int cnt = 0;
    while(k)
    {
        k /= 3;
        cnt++;
    }
    return cnt;
}
// void Minimum_operation(int l, int r)
// {
//     int total = 0;
//     int t = (r - l + 1);
//     total += 2*Etimes(l) + Etimes((l + 1));
//     if(t > 2)
//     {
//         for(int i = l + 2; i <= r; i++)
//         {
//             total += Etimes(i);
//         }
//         cout << total << endl;
//     }
//     else
//     {
//         cout << total << endl;
//     }
// }

void output (int l, int r)
{
    cout << num[r] - num[l - 1] + a[l] << endl;
}
int main()
{
    //高效处理输入输出
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    for(int i = 1; i < MAX; i++)
    {
        a[i] = Etimes(i);
        num[i] = num[i - 1] + a[i];
    }
    int n = 0;
    cin >> n;
    while(n--)
    {
        int l, r;
        cin >> l >> r;
        output(l, r);
    }
}