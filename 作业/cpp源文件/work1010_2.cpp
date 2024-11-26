#include <iostream>
#include <vector>

int main() {
    // 枚举所有可能的名次
    for (int a = 1; a <= 4; ++a) {
        for (int b = 1; b <= 4; ++b) {
            for (int c = 1; c <= 4; ++c) {
                for (int d = 1; d <= 4; ++d) {
                    // 确保名次不重复
                    if (a != b && a != c && a != d &&
                        b != c && b != d &&
                        c != d) {
                        
                        // 预测对的计数
                        // 如果判断为true返回1，反之返回0
                        int correctA = (a == 1) + (b == 3); // 甲
                        int correctB = (c == 1) + (d == 4); // 乙
                        int correctC = (d == 2) + (a == 3); // 丙
                        
                        // 每位老师预测对了一半
                        if (correctA == 1 && correctB == 1 && correctC == 1) {
                            std::cout << "学生a的名次: " << a << std::endl;
                            std::cout << "学生b的名次: " << b << std::endl;
                            std::cout << "学生c的名次: " << c << std::endl;
                            std::cout << "学生d的名次: " << d << std::endl;
                            return 0; // 找到符合条件的解后退出
                        }
                    }
                }
            }
        }
    }
    
    std::cout << "没有符合条件的名次组合。" << std::endl;
    return 0;
}
