#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int cnt[10];
void check(int a)
{
    while(a)
    {
        int k = a % 10;
        a /= 10;
        cnt[k]++;
    }
}
int main()
{
    // int a, b;
    // scanf("%d*%d=", &a, &b);
    // printf("%d\n", a*b);
    double a, b, k;
    cin >> a >> b >> k;
    vector<pair<int, double>> vec;
    
    return 0;
}
