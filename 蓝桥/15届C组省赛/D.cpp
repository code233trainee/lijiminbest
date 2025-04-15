#include <bits/stdc++.h>
using namespace std;
int num[] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};
//注意， 0也是封闭图形啊
int check(int n)
{
    int cnt = 0;
    while(n)
    {
        int a = n % 10;
        n /= 10;
        cnt += num[a];
    }
    return cnt;
}
bool cmp(int a, int b)
{
    if(check(a) != check(b))
    {
        return check(a) < check(b);
    }
    else
    {
        return a < b;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), cmp);
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}