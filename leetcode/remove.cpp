#include <iostream>
#include <vector>
int main()
{
    std::vector<int> nums = {1,1,2};
    int count = 0;
    int size = nums.size();
    for(int i = 1; i <= size; i++)
    {
        if(nums[i] == nums[i - 1] )
        {
            nums[i] = nums[i + 1];
            count += 1;
        }
    }
    for(int i = 0; i < size - count; i++ )
    {
        std::cout << nums[i] << ",";
    }
    
}
