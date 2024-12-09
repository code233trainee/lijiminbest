#include <bits/stdc++.h>
using namespace std;
void solve(int &sum1, int &sum2, int &sum3, int i)
{
    int a, b, c, d, e;
    e = i%10;
    i /= 10;
    d = i%10;
    i /= 10;
    c = i%10;
    i /= 10;
    b = i%10;
    a = i / 10;   
    sum1 = a*100+b*10+c*1;
    sum2 = b*100+c*10+d*1;
    sum3 = c*100+d*10+e*1;
}
int main()
{
    int k;
    cin >> k;
    bool ok = false;
    int sum1 = 0, sum2 = 0, sum3 = 0;
    for(int i = 10000; i <= 30000; i++)
    {
        solve(sum1, sum2, sum3, i);
        if(sum1%k == 0 && sum2%k == 0 && sum3%k == 0)
        {
            cout << i << endl;
            ok = true;
        }
    }
    if(!ok)
    {
        cout << "No" << endl;
    }
    return 0;
}