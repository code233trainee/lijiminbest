#include <bits/stdc++.h>
using namespace std;
int check(int k)
{
    int sum = 0;
    while(k)
    {
        int a = k%10;
        k /= 10;
        sum += a;
    }
    return sum;
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }
    sort(a.begin(), a.end(), cmp);
    cout << a[m-1];
    return 0;
}