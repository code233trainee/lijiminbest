#include <bits/stdc++.h>
using namespace std;
int main()
{
    //点的度是动态统计的，也就是说攻击一个度的点之后
    //与其相连的点的度就会减一
    //我们构造的图就是找到两个"牺牲点"，牺牲点被删除后，其他的点度都会减一
    //就避开了攻击
    int n;
    cin >> n;
    if(n <= 2)
    {
        cout << "0\n";
    }
    else
    {
        cout << n-2 << "\n";
    }
    return 0;
}