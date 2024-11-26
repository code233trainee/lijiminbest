#include "Vector.h"
#include <iostream>
int main()
{
    srand(time(NULL));//设置随机种子
    Vector<int> myvector;
    // void(*a)(int&);
    // void(*b)(int&);
    // a = visit;
    // b = visit2;
    // myvector.traverse(visit);
    myvector.insert(-2);
    myvector.insert(-1);
    // cout << myvector.size() << endl;
    for (int i = 0; i < 5; i++)
    {
        myvector.insert(i);
    }
    myvector.traverse(visit);
    cout << endl;

    for (int i = 0; i < 5; i++)
    {
        myvector.insert(2, 0);
    }
    myvector.traverse(visit);
    cout << endl;
    
    //去重
    // myvector.deduplicate();
    int k = myvector.uniquify();
    cout << "共删除了" << k << "个重复元素" << endl;

    myvector.traverse(visit);
    cout << endl;

    //置乱
    permute(myvector);
    //二次置乱
    myvector.unsort();
    cout << "置乱后的向量:";
    myvector.traverse(visit);
    cout << endl;

    cout << "移除秩为2的元素: " << myvector.remove(2) << endl;
    cout << "移除后的向量:";
    myvector.traverse(visit);
    cout << endl;

    myvector.sort();
    cout << "使用归并排序后的向量:";
    myvector.traverse(visit);
    cout << endl;
    // myvector.traverse(visit2);
    // cout << myvector.size() << endl;
    cout << "将向量中的元素都加1后:";
    increase(myvector);
    myvector.traverse(visit);
    cout << endl;

    cout << "查找元素3:";
    int r = myvector.search(3);
    if(r == -1)
    {
        cout << "没有找到你要的元素" << endl;
    }
    else
    {
        cout << "此元素的秩为:" << r << endl;
    }
}