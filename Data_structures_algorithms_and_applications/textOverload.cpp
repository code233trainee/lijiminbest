#include "currencyOverload.h"

int main()
{
   currencyOverload g,h(currencyOverload::signType::plus, 3, 5),i,j;
    //两种形式的setValue
    g.setValue(currencyOverload::signType::plus, 2, 25);
    i.setValue(-6.45);

    //调用成员函数add和output
    j = h + g;
    std::cout << h << " + " << g << " = " << j << std::endl;

    //连续两次调用成员函数 add
    j = i + g + h;
    std::cout << i << " + " << g << " + "
              << h << " = " << j << std::endl;

    //调用成员函数increment和add
    std::cout << "Increment " << i << " by " << g
              << " and then add " << h << std::endl;
    j = (i += g) + h;
    std::cout << "Result is " << j << std::endl;
    std::cout << "Increment object is " << i << std::endl;

    //测试异常
    std::cout << "Attempting to initialize with cents = 152" << std::endl;
    try
    {
        i.setValue(currencyOverload::signType::plus, 3, 152);
    }
    catch(illegalParameterValue e)
    {
        std::cout << "Caught thrown exception" << std::endl;
        // std::cerr << e.what() << '\n';
        e.outputMessage();
    }
    
}