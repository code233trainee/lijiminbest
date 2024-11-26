#include <iostream>
#include <vector>
using namespace std;

std::string sa[10];
int ia[10]; //10个元素，每个元素都是0(全局静态作用域)
int main()
{
    std::vector<int> v = {10};
    std::vector<int> vr(10, 0);//vr中有10个0
    std::vector<int> vrr(vr);//vrr中含有vr中的所有元素的副本 与vrr = vr等价

    const char a5[6]="Danie";//使用字符串字面值初始化数组时要预留一个空间存放空字符

    std::string sa2[10];
    int ia2[10];

    int arr[10] = {}; //10个元素，每个元素都是0
    int otarr[10];
    for(int j = 0; j < 10; j++)
    {
        otarr[j] = arr[j];
    }
    int (*Parray)[10] = &arr; //Parray指向一个含有10个整数的数组
    size_t size = 100;    

    cout << "这是arr的输出:" << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
        // cout << Parray[i] << endl;
    }

    int *p = arr;
    cout << "这是指针p的输出:" << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << p[i] << endl;
    }

    int iaa[] = {1, 2, 3, 4, 5};
    auto pi(iaa); //pi的类型是指针 (这里指向iaa的第一个元素)
    ++pi;//指向pi的第二个元素
    int *e = &iaa[5];//指向最后一个元素后面那个并不存在的元素
    cout << "这是指针pp的输出:" << endl;
    for(int *pp = iaa; pp != e; ++pp)
    {
        cout << *pp << endl;
    }

}