//给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
//你可以按任意顺序返回答案。
#include <iostream>
#include <vector>
using namespace::std;
//int subscript(vector<int> s,int &a,int b) (这是一个寻找数组中对应下标的函数)
//{
//    for(int d=a+1;d<s.size();d++)
//    {
//        if(s.at(d)==b)
//        a=d;
//        return static_cast<int>(d);
//    }
//    return -1;
//}
int main()
{
    vector<int> num{2,11,15,7};
    int target=9;
    vector<int> ans{};
    auto k=num.begin();
    int e=0;
    for(auto i=num.begin();i!=num.end();)
    {
        int b=*i;
        i++;
        k=i;
        while(k!=num.end())
        {
            
            if(target==(*k)+b)
            {
                for(int i=0;i<num.size();i++)
                {
                    for(int j=i+1;j<num.size();j++)
                    {
                        if(num[i]+num[j]==target)
                        {
                            ans.push_back(i);
                            ans.push_back(j);
                        }
                    }

                }
                

            }
            k++;
        }
        
    }
    for (auto c : ans)
    {
        cout<<c<<" ";
    }
}