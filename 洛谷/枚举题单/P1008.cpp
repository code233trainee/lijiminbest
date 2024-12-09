#include <bits/stdc++.h>
using namespace std;
void solve(map<int, int> &ma, int sum)
{
    ma[sum%10]++;
    sum /= 10;
    ma[sum%10]++;
    sum /= 10;
    ma[sum]++;
}
int main()
{
    for(int i = 123; i <= 333; i++)
    {
        map<int, int> ma;
        int sum = i;
        int sum2 = 2 * sum;
        int sum3 = 3 * sum;
        solve(ma, sum);
        solve(ma, sum2);
        solve(ma, sum3);
        ma.erase(0);
        if(ma.size() == 9)
        {
            cout << sum << " " << sum2 << " " << sum3 << endl;
        }
    }
                

    return 0;
}