#include <bits/stdc++.h>
using namespace std;
//能被4整除但是不能被100整除，或者能被400整除的，为闰年(二月有29号)
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100!= 0) || (year % 400 == 0);
}
int main()
{
    int year;
    cout << "请输入一个年份: ";
    cin >> year;
    if (isLeapYear(year)) {
        cout << year << " 是闰年" << endl;
    } else {
        cout << year << " 不是闰年" << endl;
    }
    return 0;
}