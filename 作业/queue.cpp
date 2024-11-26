#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;
    int num = 0;
    while(true)
    {
        int input;
        std::cout << "请输入一个数: ";
        std::cin >> input;
        
        if(input == 0)
        {
            if(q.empty())
            {
                std::cout << "可以下班了" << std::endl;
                break;
            }
            else
            {
                std::cout << "还有客户在排队哦" << std::endl;
            }
        }
        else
        {
            switch(input)
            {
                case 1:
                    num++;
                    q.push(num);
                    std::cout << "当前排队人数：" << q.size() << std::endl;
                    break;
                case 2:
                    if(q.empty())
                    {
                        cout << "当前无人排队" << endl;
                        break;
                    }
                    else
                    {
                        std::cout << "当前客户:" << q.front() << std::endl;
                        std::cout << "前面还有:" << q.size() - 1 << "人" << std::endl;
                        q.pop();
                        std::cout << q.front();
                        break;
                    }
            }
        }
        
    }
}