#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int gcd(int a, int b)
{
    while(b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
//a是进制，b是要转换的数字
int convertToBase(int a, int b)
{
    int sum = 0;
    while(b > 0)
    {
        sum += b%a;
        b /= a;
    }
    return sum;
}
int main()
{
    int n;
    cin >> n;
    int low = 0, high = 0;
    for(int i = 2; i <= n-1; i++)
    {
        high += convertToBase(i, n);
    }
    low = n - 2;
    int g = gcd(low, high);
    low /= g;
    high /= g;
    cout << high << "/" << low << "\n";
    return 0;
}