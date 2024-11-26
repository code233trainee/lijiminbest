#include <iostream>
#include <string>
int main()
{
    for(int i=1;i<=9;i++)
    {
        for ( int j = 1; j <= i; j++ )
        {
            std::cout<<j<<"X"<<i<<"="<<i*j<<" ";
        }
        std::cout<<"\n";
    }
}