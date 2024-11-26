//给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

//不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。

//元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。


//说明:
//为什么返回数值是整数，但输出的答案是数组呢?
//请注意，输入数组是以「引用」方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。
//你可以想象内部操作如下:
// nums 是以“引用”方式传递的。也就是说，不对实参作任何拷贝
//int len = removeElement(nums, val);
// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中 该长度范围内 的所有元素。
//for (int i = 0; i < len; i++) {
//    print(nums[i]);
//}


//不需要考虑数组的顺序，只需要考虑移除的元素不在数组内
//要保证val不在数组类只需要输出数组的前几个元素
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> nums{0,2,3,3,4};
    int val=2;
    int l=0,r=nums.size()-1;//定义两个指针，分别从数组的第一个元素和最后一个元素开始
    while(l<=r)
    {
        if(nums[l]==val)
        {   //交换这两个数的位置
            int tmp=nums[l];
            nums[l]=nums[r];
            nums[r]=tmp;
            r--;
        }
        else
        {
            l++;
        }   
    }
    //原题返回r+1即为需要输出的数组元素的个数
    cout<<"需要的元素个数："<<r+1<<endl;
    for(auto k:nums)
    {
        cout<<k<<" ";
    }
}