#include <string>
#include <iostream>
#include "Sales_item.h"
#include "Sales_item.h"
struct Sales_item
{
    std::string book_isbn;
    int quantity = 0;
    double Price = 0;

};
//书店程序
int main()
{
    Sales_item item1{"0-201-78345x",4,33.0};
    Sales_item item2{"0-201-78346x",5,33.0};

    std::cout<<"请输入书号，数量，价格：";
    std::cin>>item1.book_isbn>>item1.quantity>>item1.Price;
    
    std::cout<<"请输入书号，数量，价格：";
    std::cin>>item2.book_isbn>>item2.quantity>>item2.Price;

    if(item1.book_isbn==item2.book_isbn)
    {
        std::cout<<item1.book_isbn<<" "
                 <<item1.quantity+item2.quantity<<" "
                 <<(item1.quantity+item2.quantity)*item1.Price
                 <<std::endl;
    }
    else
    {
        std::cout<<item1.book_isbn<<" "
                 <<item1.quantity<<" "
                 <<item1.Price*item1.quantity
                 <<std::endl;

        std::cout<<item2.book_isbn<<" "
                 <<item2.quantity<<" "
                 <<item2.Price*item2.quantity
                 <<std::endl;
                 
    }
    printf("*");
}