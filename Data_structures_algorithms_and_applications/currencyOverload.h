#include <iostream>


#ifndef currencyOverload_
#define currencyOverload_

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

class currencyOverload
{
    //友元函数
    friend std::ostream& operator<<(std::ostream&, const currencyOverload&);
    public:
        enum signType
            {
                plus,//"+"
                minus//"-"
            };
        //构造函数
        currencyOverload(signType theSign = plus,
                         unsigned long theDollars = 0,
                         unsigned int theCents = 0)
        {
            setValue(theSign,theDollars,theCents);
        }
        //析构函数
        ~currencyOverload() {}
        
        //异常处理
        // std::runtime_error illegalParameterValue(std::string s)
        // {
        //     return std::runtime_error(s);
        // }

        void setValue(signType theSign, unsigned long theDollars, unsigned theCents)
        {
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
        
        void setValue(double theAmount)
        {
            if(theAmount < 0)
            {
                amount = (long) ((theAmount - 0.001) * 100);
            }
            else
            {
                amount = (long) ((theAmount + 0.001) * 100);
            }
        }

        // signType getSign() const
        // {
        //     if(amount < 0)
        //     {
        //         return minus;
        //     }
        //     else
        //     {
        //         return plus;
        //     }
        // }

        // unsigned long getDollars() const
        // {
        //     if(amount < 0)
        //     {
        //         return (-amount) / 100;
        //     }
        //     else
        //     {
        //         return amount / 100;
        //     }
        // }

        // unsigned int getCents() const
        // {
        //     if(amount < 0)
        //     {
        //         return -amount - getDollars() * 100;
        //     }
        //     else
        //     {
        //         return amount - getDollars() * 100;
        //     }
        // }

        //把参数对象x和调用对象*this相加
        currencyOverload operator+(const currencyOverload& x) const
        {
            currencyOverload result;
            result.amount = amount + x.amount;
            return result;
        }

        currencyOverload operator+=(const currencyOverload& x)
        {
            amount += x.amount;
            return *this;
        }

        //把货币值插入流 out
        void currencyOverload::output(std::ostream& out) const
        {
            long theAmount = amount;
            if(theAmount < 0)
            {
                out << '-';
                theAmount = -theAmount;
            }
            long dollars = theAmount / 100;//美元
            out << '$' << dollars << '.';

            int cents = theAmount - dollars * 100;//美分
            if(cents < 10)
            {
                out << '0';
            }  
            out << cents;
        }

        private:
            long amount;
};

//重载 <<
std::ostream& operator<<(std::ostream& out, const currencyOverload& x)
{//把货币流插入流out
    long theAmount = x.amount;
    if(theAmount < 0)
    {
        out << '-';
        theAmount = -theAmount;
    }
    long dollars = theAmount / 100;//美元
    out << '$' << dollars << '.';
    int cents = theAmount - dollars * 100;//美分
    if(cents < 10)
    {
        out << '0';
    }
    out << cents;

    //
    // x.output(out);
    return out;
}
#endif
