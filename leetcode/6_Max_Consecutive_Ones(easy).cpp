//给定一个二进制数组 nums ， 计算其中最大连续 1 的个数。
//数组中只会出现0或1

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> nums={1,1,0,1,1,1};
    int ret=0,per=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                per++;
                if(ret<per)
                ret=per;//每次都把最新的连续个数储存到ret
            }
            else
            {
                per=0;//如果遇到零则重新计数
            }
        }
    cout<<"最大连续1的个数为:"<<ret;
}