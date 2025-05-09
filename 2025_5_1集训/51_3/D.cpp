// https://acm.hdu.edu.cn/showproblem.php?pid=2897
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, p, q;
    while(cin >> n >> p >> q)
    {
        int temp = n % (p + q);
        if(temp == 0)
        {
            temp = p + q;
        }
        if(temp <= p)
        {
            cout << "LOST" << endl;
        }
        else
        {
            cout << "WIN" << endl;
        }
    }
    return 0;
}