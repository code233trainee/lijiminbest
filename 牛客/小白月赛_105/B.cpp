// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     string a, b;
//     cin >> a >> b;

// }
#include <iostream>
#include <string>
using namespace std;

int compareDecimalsTo6(const string& num1, const string& num2) {
    // 分割整数部分和小数部分
    //size_t
    size_t dot1 = num1.find('.'), dot2 = num2.find('.');//如果没找到会返回string::npos
    string intPart1 = dot1 == string::npos ? num1 : num1.substr(0, dot1);//获取小数点前面部分的字符
    string decPart1 = dot1 == string::npos ? "" : num1.substr(dot1 + 1);//获取小数点后面的字符(如果没有就是空字符串)
    string intPart2 = dot2 == string::npos ? num2 : num2.substr(0, dot2);
    string decPart2 = dot2 == string::npos ? "" : num2.substr(dot2 + 1);

    // 补齐小数部分到6位并截断
    while (decPart1.size() < 6) decPart1 += '0';
    while (decPart2.size() < 6) decPart2 += '0';
    decPart1 = decPart1.substr(0, 6);
    decPart2 = decPart2.substr(0, 6);

    // 比较整数部分
    if (intPart1.size() != intPart2.size()) {
        return intPart1.size() > intPart2.size() ? 1 : -1;
    }
    if (intPart1 != intPart2) {
        return intPart1 > intPart2 ? 1 : -1;
    }

    // 比较小数部分
    if (decPart1 != decPart2) {
        return decPart1 > decPart2 ? 1 : -1;
    }

    // 完全相等
    return 0;
}

int main() {
    string num1, num2;
    cin >> num1 >> num2;

    int result = compareDecimalsTo6(num1, num2);
    if (result == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
