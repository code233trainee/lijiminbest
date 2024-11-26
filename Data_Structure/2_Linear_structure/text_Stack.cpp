#include "Stack.h"
int main()
{
    
    // int i = 3;
    // int j = 2;
    // if( i > j) std::cout << "第一个分支"; std::cout << "第二个分支";
    Stack<char> s, k;
    convert(s, 2, 2);
    while(s.size())//栈大小动态变化
    {
        cout << s.pop();
    }
    cout << endl;

    char* a = "(1+1)*2\0";
    char* r;
    int output = evaluate(a, r);
    cout << output << endl;
    cout << r << endl;
    cout << pri[8][8] << endl;
}