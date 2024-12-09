#include <bits/stdc++.h>
using namespace std;
bool isPrime(int num) {
    if (num < 2) {  // 小于2的数不是质数
        return false;
    }
    if (num == 2) {  // 2是质数
        return true;
    }
    if (num % 2 == 0) {  // 能被2整除（除了2本身）的都不是质数
        return false;
    }
    // 只需要判断到该数的平方根即可，因为如果一个数不是质数，
    // 那么它必然可以分解成两个因数，其中一个小于等于它的平方根，另一个大于等于它的平方根
    for (int i = 3; i <= std::sqrt(num); i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a;
    a.push_back(2);
    for(int i = 3; i < 20000; i++)
    {
        if(isPrime(i))
        {
            a.push_back(i);
        }
    }
    int tt = a.size();
    for(int i = 0; i < tt; i++)
    {
        for(int j = 0; j < tt; j++)
        {
            for(int k = 0; k < tt; k++)
            {
                if(a[i] + a[j] + a[k] == n)
                {
                    cout << a[i] << " " << a[j] << " " << a[k];
                    return 0;
                }
            }
        }
    }
    return 0;
}