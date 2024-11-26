#include <bits/stdc++.h>
using namespace std;
int reverse(int number)
{
    int digit = 0, flag = 0, res = 0;
    
    int count = 0;
    flag = number < 0 ? -1 : 1;
    if(flag < 0)
    {
        number = -number;
    }
    int num = number;
    while (num != 0) {
        num /= 10;
        count++;
    }
    do{
        digit = number % 10;
        res += digit * pow(10, count); 
        number /= 10;
        count--;
    }while(number != 0);
    return flag * res;
}
int main()
{
    int t = 0;
    cin >> t;
    cout << reverse(t) << endl;
}