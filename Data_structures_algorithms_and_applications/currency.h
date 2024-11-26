#include <iostream>
#ifndef currency_
#define currency_
//类的构造函数在声明时会被调用一次(new,直接声明),
//new出来的对象时在堆上，直接声明的对象是在栈上
//类的析构函数在类的变量生命周期结束时调用.
//new的对象需要手动delet结束(会调用析构函数)否则会内存泄漏,
//直接声明的对象则在函数返回，或者在作用域结束时(一次花括号)自动调用一次析构函数(例如for，while循环).
class illegalParameterValue
{
    public:
        illegalParameterValue():
            message("Illegal parameter value"){}
        illegalParameterValue(char* theMessage)
        {
            message = theMessage;
        }
        void outputMessage()
        {
            std::cout << message <<std::endl;
        }
    private:
        std::string message;

};

class currency
{
    public:
        enum signType
        {
            plus,//"+"
            minus//"-"
        };
        //构造函数
        currency(signType theSign = plus,
                unsigned long theDollars=0,
                unsigned int theCents=0)
        {
            // std::cout<<"调用构造函数"<<std::endl;
            setValue(theSign,theDollars,theCents);//创建一个currency类对象
        }

                
        //析构函数
        ~currency() 
        {
            // std::cout<<"调用析构函数"<<std::endl;
        }

        //异常处理
        // std::runtime_error illegalParameterValue(std::string s)
        // {
        //     return std::runtime_error(s);
        // }

        //给调用对象的数据成员赋值
        void setValue(signType theSign, unsigned long theDollars, unsigned int theCents)
        {
            // if(theCents > 90)
            // {
            //     throw illegalParameterValue("Cents should be < 100");
            // }
            // sign = theSign;
            // dollars = theDollars;
            // cents = theCents;

            //不同的描述方法
            if(theCents > 90)
            {
                throw illegalParameterValue("Cents should be < 100");
            }
            amount = theDollars * 100 + theCents;
            if(theSign == minus)
            {
                amount = -amount;
            }   
        }

        //给调用对象的数据成员赋值
        void currency::setValue(double theAmount)
        {
            // if(theAmount < 0)
            // {
            //     sign = minus;
            //     theAmount = -theAmount;
            // }
            // else
            // {
            //     sign = plus;
            // }
            // dollars = (unsigned long) theAmount;                         //提取整数部分
            // cents = (unsigned int) ((theAmount + 0.001 - dollars) * 100);//提取两位小数

            //不同的描述方法
            if(theAmount < 0)
            {
                amount = (long) ((theAmount - 0.001) * 100);
            }
            else
            {
                amount = (long) ((theAmount + 0.001) * 100);
            }
            //取两个十位数
        }


        signType getSign() const 
        {
            return sign;
        }        
        unsigned long getDollars() const 
        {
            return dollars;
        }
        unsigned int getCents() const
        {
            return cents;
        }


        //把x和*this相加
        currency currency::add(const currency& x) const
        {
            // long a1,a2,a3;
            // currency result;

            // //把调用对象转化为符号整数
            // a1 = dollars * 100 + cents;
            // if(sign == minus)
            // {
            //     a1 = -a1;
            // } 
            
            // //把x转为符号整数
            // a2 = x.dollars * 100 + x.cents;
            // if(x.sign == minus)
            // {
            //     a2 = -a2;
            // }

            // a3 = a1 + a2;
            // //转换为currency对象的表达式
            // if(a3 < 0)
            // {
            //     result.sign = minus;
            //     a3 = -a3;
            // }
            // else 
            // {
            //     result.sign = plus;
            // }
            // result.dollars = a3 / 100;
            // result.cents = a3 - result.dollars * 100;
            // return result;

            //不同的描述方法
            currency y;
            y.amount = amount + x.amount;
            return y;
        }

        //增加x
        currency& currency::increment(const currency& x)
        {
            *this = add(x);//this指向调用这个函数的对象
            return *this;
        }

        //输出调用对象的值
        void currency::output() const
        {
            // if(sign == minus)
            // {
            //     std::cout << '-';
            // }
            // std::cout << '$' << dollars << '.';
            // if(cents < 10)
            // {
            //     std::cout << '0';
            // }
            // std::cout << cents;

            //不同的描述方法
            long theAmount = amount;
            if(theAmount < 0)
            {
                std::cout << '-';
                theAmount = -theAmount;
            }
            long dollars = theAmount / 100;//美元
            std::cout << '$' << dollars << '.';
            int cents = theAmount - dollars * 100;//美分 
            if(cents < 10)
            {
                std::cout << '0';
            }
            std::cout << cents;

        }
    private:
        signType sign;//对象的符号
        unsigned long dollars;//美元的数量
        unsigned int cents;//美分的数量

        //不同的描述方法
        long amount;//仅有一个私有数据成员
};
#endif