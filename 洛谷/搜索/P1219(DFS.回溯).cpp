#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int a[100], b[100], c[100], d[100];
// a数组表示的是行
// b数组表示的是列
// c表示的左下到右上的对角线
// d表示的右下到左上的对角线
int total = 0;//解的总数
int n = 0;//棋盘大小
void Print()
{
    if(total <= 2)
    {
        for(int k = 1; k <= n; k++)
        {
            cout << a[k] << " ";
        }
        cout << endl;
    }
    total++;
}
void queen(int i)
{
    if(i > n)
    {
        Print();
        return;
    }
    else
    {
        for(int j = 1; j <= n; j++)
        {
            //如果没有皇后占领
            if((!b[j]) && (!c[i+j]) && (!d[i-j+n]))
            {
                a[i] = j;//标记第i排是第j个
                b[j] = 1;
                c[i + j] = 1;
                d[i - j + n] = 1;
                queen(i+1);
                b[j] = 0;
                c[i+j] = 0;
                d[i-j+n] = 0;
                //回到上一步
            }
        }
    }
}
int main()
{
    cin >> n;
    queen(1);
    cout << total << endl;
    return 0;
}