#include "list.h"
int main()
{
    List<int> list ;
    list.insertAsLast(12);
    list.insertAsLast(13);
    list.insertAsLast(1);
    list.insertAsLast(9);
    list.insertAsLast(9);
    list.insertAsLast(9);
    list.insertAsLast(7);
    list.insertAsLast(8);
    list.insertAsLast(15);
    list.insertAsLast(14);

    cout << "插入后的列表:" << endl; 
    print(list);

    cout << "排序后的列表:" << endl; 
    list.sort();
    print(list);

    cout << "有序列表去除重复项:" << endl;
    list.uniquify();
    print(list);

    cout << "移除元素9:" << endl;
    list.remove(list.search(9));
    print(list);

    cout << "列表大小：" << list.size() << endl;


    // int a = list.remove(list.header->succ);
    // cout << a << endl;
}