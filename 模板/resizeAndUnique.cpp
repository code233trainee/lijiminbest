#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> c(10, 1);
    //要记得先排序
    sort(c.begin(), c.end());
    //去除重复元素并且重新设置大小，这样设置之后的数字就只有不重复的元素了
    c.resize(unique(c.begin(), c.end()) - c.begin());
}
