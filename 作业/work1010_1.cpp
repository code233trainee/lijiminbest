// #include <iostream>

// int main()
// {
//     int a, b, c, number;
//     int total = 0;
//     for(a = 1; a < 10; a++)
//     {
//         total += a*10000;
//         for(b = 0; b < 10; b++)
//         {
//             total += b * 1000;
//             for(c = 0; c < 10; c++)
//             {
//                 total += c * 100;
//                 total += a * 10;
//                 total += b;
//                 number = total * a;
//                 if(number >= 100000 && number <= 999999)
//                 {
//                     std::cout << number << std::endl;
//                     if((number / 100000 == (number / 10000) % 10) &&
//                     ((number / 10000) % 10 == (number / 1000) % 10) &&
//                     ((number / 1000) % 10 == (number / 100) % 10) &&
//                     ((number / 100) % 10 == (number / 10) % 10) &&
//                     ((number / 10) % 10 == number % 10))
//                     {
//                         std::cout << a << b << c << a << b << std::endl;
//                         std::cout << "total:" << number << std::endl;
//                     }
//                 }
  
//             }
//         }
//     }
//     // int k = 100; abcab
//     // a = k % 10;
//     // std::cout << a << std::endl;
//     // std::cout << k << std::endl;
// }

#include <iostream>
int main() {
    // 穷举a, b, c的可能值
    for (int a = 1; a <= 9; ++a) {  // a的范围从1到9
        for (int b = 0; b <= 9; ++b) {
            for (int c = 0; c <= 9; ++c) {
                // 构造五位数abcab
                int number = 10010 * a + 1001 * b + 100 * c;

                // 计算number乘以a的结果
                int result = number * a;

                // 检查结果是否是一个六位数，并且每一位数字都相同
                if (result >= 100000 && result < 1000000) {
                    // 提取result的每一位数字
                    int digit = result % 10;  // 取个位
                    int temp = result;
                    bool allSame = true;

                    // 检查每一位是否都相同
                    while (temp > 0) {
                        if (temp % 10 != digit) {
                            allSame = false;
                            break;
                        }
                        temp /= 10;
                    }

                    // 如果满足条件，输出结果
                    if (allSame) {
                        std::cout << "存在这样的五位数：" << number
                                  << "，乘以 " << a << " 得到的六位数是 " << result << std::endl;
                        return 0;
                    }
                }
            }
        }
    }

    std::cout << "没有符合条件的五位数存在。" << std::endl;
    return 0;
}
