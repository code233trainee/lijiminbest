#include <iostream>
#include <vector>
int main()
{
    std::vector<int> digits = {9};
    for(int i = digits.size() - 1; i >= 0; i-- )
        {
            if(digits[i] != 9)
            {
                digits[i]++;
                break;
            }
            else
            {
                digits[i] = 0;
            }
        }
        int se =digits.size() + 1; 
        std::vector<int> tmp;
        for(int i = 0; i < digits.size() + 1; i++ )
        {
            tmp[i] = 0;
        }
        tmp[0] = 1;
        std::cout << tmp[1] << std::endl;
        return 0;
}