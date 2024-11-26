#pragma once

#include <iostream>
using namespace std;
typedef int Rank;
#define DEFAULT_CAPACITY 3 //默认初始容量

//"Fib.h"
class Fib { //Fibonacci 斐波那契数列类
private:
   Rank f, g; //f = fib(k - 1), g = fib(k)
public:
   Fib ( Rank n ) 
   { f = 1; g = 0; while ( g < n ) next(); } 
   Rank get()  { return g; } 
   Rank next() { g += f; f = g - f; return g; } 
   Rank prev() { f = g - f; g -= f; return g; } 
};


template <typename T> 
class Vector
{
    //可以在类的内部、派生类（子类）内部访问，但不能在类的对象或派生类的对象中直接访问。
    protected:
        Rank _size; int _capacity; T* _elem;// 规模，容量，数据区
        void copyFrom(T const* A, Rank lo, Rank hi)// 复制数组区间A[lo, hi)
        {
            _elem = new T[_capacity = 2 * (hi - lo)];//双倍的空间
            _size = 0;//分配空间，规模清零
            while(lo < hi)
            {
                _elem[_size++] = A[lo++];//逐一复制至_elem[0, hi - lo]
            }
        }
        void expand()// 空间不足时扩容(填装因子过大)(填装因子:向量的实际规模/内部数组的容量的比值)
        {
            if (_size < _capacity)//空间未满时不必扩容
            {
                return;
            }
            if (_capacity < DEFAULT_CAPACITY)//不低于最小容量
            {
                _capacity = DEFAULT_CAPACITY;
            }
            T* oldElem = _elem;
            _elem = new T[_capacity <<= 1];//容量加倍("<<="将变量向左移动指定的位数，并将结果赋值给变量)
            for(int i = 0; i < _size; i++)
            {
                _elem[i] = oldElem[i];//复制原向量内容(T为基本类型，或已重载赋值操作符'=')
            }
            delete [] oldElem;//释放原空间
        }
        void shrink()// 填装因子过小时压缩(填装因子:向量的实际规模/内部数组的容量的比值)
        {
            if(_capacity < DEFAULT_CAPACITY << 1)//不至于收缩到DEFAULT_CAPACITY以下
            {
                return;
            }
            if(_size << 2 > _capacity)//以%25为边界
            {
                return;
            }
            T* oldElem = _elem;
            _elem = new T[_capacity >>= 1];//容量减半
            for(int i = 0; i < _size; i++)
            {
                _elem[i] = oldElem[i];//复制原向量内容
            }
            delete [] oldElem;//释放原空间
        }

        //排序
        bool bubble(Rank lo, Rank hi)// 扫描交换
        {
            bool sorted = true;//整体有序标志
            //先自增再比较
            while(++lo < hi)//自左向右，逐一检查各对相邻元素
            {
                if(_elem[lo - 1] > _elem[lo])//若逆序,则说明未整体有序,并需要通过交换使局部有序
                {
                    sorted = false;
                    swap(_elem[lo - 1], _elem[lo]);
                }
            }
            return sorted;//返回有序标志
        }
        void bubbleSort(Rank lo, Rank hi)// 起泡排序
        {
            while(!bubble(lo, hi--));//逐次做扫描交换，直至全序
        }

        Rank max(Rank lo, Rank hi);// 选择最大元素
        void selectionSort(Rank lo, Rank hi)// 选择排序
        {

        }

        void merge(Rank lo, Rank mi, Rank hi)// 归并算法
        {
            T* A = _elem + lo;//合并后的向量A[0, hi - lo) = _elem[lo, hi)
            int lb = mi - lo;
            T* B = new T[lb];//前子向量B[0, lb) = _elem[lo, mi)
            for(Rank i = 0; i < lb; B[i] = A[i++]);//赋值前子向量
            int lc = hi - mi;
            T* C = _elem + mi;//后子向量C[0, lc) = _elem[mi, hi)
            for(Rank i = 0, j = 0, k = 0; (j < lb) || (k < lc);)//B[j]和C[k]中的小者续至A末尾
            {
                if((j < lb) && (! (k < lc) || (B[j] <= C[k])))
                {
                    A[i++] = B[j++];
                }
                if((k < lc) && (! (j < lb) || (C[k] < B[j])))
                {
                    A[i++] = C[k++];
                }
            }
            delete [] B;//释放临时空间B
        }//归并后得到完整的有序向量[lo, hi)
        void mergeSort(Rank lo, Rank hi)// 归并排序算法
        {
            if(hi - lo < 2)
            {
                return;//单元素区间自然有序,否则...
            }
            int mi = (lo + hi) / 2;//以中点为界
            mergeSort(lo, mi);
            mergeSort(mi, hi);//分别排序
            merge(lo, mi, hi);//归并
        }

        Rank Partition(Rank lo, Rank hi)// 轴点构造算法
        {

        }
        void quickSort(Rank lo, Rank hi)// 快速排序算法
        {

        }
        void heapSort(Rank lo, Rank hi)// 堆排序
        {

        }
    public:
        //构造函数
        Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0)//容量为c，规模为s，所有元素初始化为v
        {
            _elem = new T[_capacity = c];
            for(_size = 0; _size < s; _elem[_size++] = v);//s <= c
        }
        Vector(T const* A, Rank n)
        {
            copyFrom(A, 0, n);//数组整体复制
        }
        Vector(T const* A, Rank lo, Rank hi)
        {
            copyFrom(A, lo, hi);//区间复制
        }
        Vector(Vector<T> const& V)
        {
            copyFrom(V._elem, 0, V._size);//向量整体复制
        }
        Vector(Vector<T> const& V, Rank lo, Rank hi)
        {
            copyFrom(V._elem, lo, hi);//向量区间复制
        }
        //析构函数
        ~Vector()
        {
            delete [] _elem;//释放内部空间
        }
        //只读访问接口
        Rank size() const
        {
            return _size;// 规模
        }
        bool empty() const
        {
            return !_size;// 判空
        }
        int disordered() const// 判断向量是否已排序
        {
            int n = 0;
            for(int i = 1; i < _size; i++)//逐一检查_size - 1相邻元素
            {
                if(_elem[i - 1] > _elem[i])
                {
                    n++;
                }
            }
            return n;//当且仅当n = 0向量有序(递增)
        }
        Rank find(T const& e) const
        {
            return find(e, 0, _size);// 无序向量的整体查找
        }
        Rank find(T const& e, Rank lo, Rank hi)// 无序向量的区间查找(O(n))
        {//input sensitive(输入敏感)
            while((lo < hi--) && (e != _elem[hi]));//从后向前，顺序查找
            return hi;//若hi < lo,则意味着失败；否则hi即命中元素的秩
        }
        Rank search(T const& e) const
        {
            return (0 >= _size) ? -1 : search(e, 0, _size);// 有序向量的整体查找
        }
        Rank search(T const& e, Rank lo, Rank hi) const// 有序向量的区间查找，确定不大于e的最后一个节点的秩
        {
            int i = rand() % 2;
            i ? cout << "使用二分查找" << endl : cout << "使用斐波那契查找" << endl;
            return(i) ?//按各50%的概率随机使用二分查找或fibonacci查找
                    binSearchA(_elem, e, lo, hi) : fibSearch(_elem, e, lo, hi);
        }
        //可写访问接口
        T& operator[] (Rank r) const//重载下标操作符，可以类似于数组的形式引用各元素
        {
            return _elem[r];//assert: 0 <= r < _size
        }
        Vector<T> & operator= (Vector const& V)//重载复制操作符，以便直接克隆向量
        {
            if(_elem)
            {
                delete [] _elem;//释放原有内容
            }
            copyFrom(V._elem, 0, V.size());//整体复制
            return *this;//返回当前对象的引用，以便链式赋值
        }
        T remove(Rank r)// 删除秩为r的元素
        {
            T e = _elem[r];//备份被删除元素
            remove(r, r + 1);//调用区间删除算法，等效于对区间[r, r + 1)的删除
            return e;//返回被删除元素
        }
        int remove(Rank lo, Rank hi)// 删除秩在区间[lo,hi)之内的元素
        {
            if(lo == hi)
            {
                return 0;//出于效率考虑，单独处理退化情况，比如remove(0, 0)
            }
            while ( hi < _size )
            {
                _elem[lo++] = _elem[hi++];//[hi, _size)顺次前移hi - lo个单元
            }
            _size = lo;//更新规模，直接丢弃尾部[lo, _size = hi)区间
            shrink();//若有必要，则缩容
            return hi - lo;//返回被删除元素的数目
        }
        Rank insert(Rank r, T const& e)// 插入元素
        {
            expand();//若有必要则扩容
            for(int i = _size; i > r; i--)
            {
                _elem[i] = _elem[i - 1];//自后向前，后继元素顺次后移一个单位
            }
            _elem[r] = e;
            _size++;//置入新元素并更新容量
            return r;//返回秩
        }
        Rank insert(T const& e)
        {
            return insert(_size, e);// 默认作为末尾元素插入
        }

        void sort(Rank lo, Rank hi)// 对[lo, hi)排序
        {
            //switch(rand() % 5)//随机选择排序算法,可更具具体问题的特点灵活选取或扩充
            switch(3)
            {
                case 1: bubbleSort(lo, hi); break;//气泡排序
                case 2: selectionSort(lo, hi); break;//选择排序
                case 3: mergeSort(lo, hi); break;//归并排序
                case 4: heapSort(lo, hi); break;//堆排序
                default: quickSort(lo, hi); break;//快速排序
            }
        }
        void sort()
        {
            sort(0, _size);//整体排序
        }

        void unsort(Rank lo, Rank hi)//对[lo, hi)置乱
        {
            T* V = _elem + lo;//将子向量_elem[lo, hi)视作另一向量V[0, hi - lo)
            for(Rank i = hi - lo; i > 0; i--)//自前向后
            {
                swap(V[i - 1], V[rand() % i]);//将V[i - 1]与V[0, i)中某一元素随机交换
            }
        }

        void unsort()
        {
            return unsort(0, _size);//整体置乱
        }
        
        int deduplicate()//无序去重(高效版)
        {
            int oldSize = _size;//记录原规模
            Rank i = 1;//从_elem[1]开始
            while ( i < _size)//逐一考察各个元素
            {   //在其前缀中寻找与之雷同者(至多一个)
                (find(_elem[i], 0, i) < 0) ? i++ : remove( i );//若无雷同则继续考查其后继，否则删除雷同者
            }
            return oldSize - _size;//向量规模变化，即被删除元素总数
        }
        // int uniquify()//有序向量去重(低效版)O(n^2)
        // {
        //     int oldSize = _size;
        //     int i = 1;//当前比对元素的秩,起始于首元素
        //     while(i < _size)//从前向后，逐一比对各对相邻元素
        //     {
        //         _elem[i - 1] == _elem[i] ? remove(i) : i++;//若雷同,则删除后者;否则转至后一元素
        //     }
        //     return oldSize - _size;//向量规模变化，即被删除元素总数
        // }
        int uniquify()//有序向量去重(高效版)O(n)
        {
            Rank i = 0, j = 0;//各对互异"相邻"元素的秩
            while( ++j < _size )//逐一扫描，直至末元素
            {
                if( _elem[i] != _elem[j])//跳过雷同者
                {
                    _elem[++i] = _elem[j];//发现不同元素时，向前移至紧邻于前者右侧
                }
            }
            _size = ++i;
            shrink();//直接截取尾部多余元素
            return j - i;//向量规模变化量，即被删除元素总数
        }


        //遍历
        //函数指针 int(*name)(int, int) 前一个括号的*号后面可以给这个函数指针起一个名字，后一个括号是这个函数指针的参数列表
        //typedef int(*name)(int, int)同理 (注意，这与原来的typedef语法不同)
        void traverse(void (*visit) (T&))//遍历(使用函数指针，只读或局部性修改)
        {
            for(int i = 0; i < _size; i++)
            {
                visit(_elem[i]);//遍历向量
            }
        }
        template <typename VST> //把函数指针理解成一个类型
        void traverse (VST& visit)//<traverse>遍历(使用函数对象，可全局性修改)
        {
            for(int i = 0; i < _size; i++)
            {
                visit(_elem[i]);//遍历向量
            }
        }
        
};


template <typename T>
//static关键字，静态，其他文件不可见
static Rank binSearchA(T* A, T const& e, Rank lo, Rank hi)//二分查找算法(版本A):在有序向量的区间[lo, hi)内查找元素e, 0 <= lo <= hi <= _size 
{//O(logn)   
    while(lo < hi)//每步迭代可能要做两次比较判断，有三个分支
    {
        Rank mi = (lo + hi) >> 1;//以中间为轴点(右移也是向下取整)
        if(e < A[mi])
        {
            hi = mi;//深入前半段[lo, mi)继续查找
        }
        else if(A[mi] < e)
        {
            lo = mi + 1;//深入后半段(mi, hi)继续查找
        }
        else
        {
            return mi;//在mi处命中
        }
    }//成功查找可以提前终止
    return -1;//查找失败
}//有多个命中元素时，不能保证返回秩最大者;查找失败时，简单的返回-1，而不能指示失败的位置

template <typename T>//二分查找算法(版本B)
static Rank binSearchB(T* A, T const& e, Rank lo, Rank hi)
{
    while(1 < hi - lo)//每步迭代仅需要做一次比较判断，有两个分支；成功查找不能提前终止
    {
        Rank mi = (hi + lo) >> 1;//以中点为轴
        (e < A[mi]) ? hi = mi : lo = mi;//经过比较后确定深入[lo, mi)或[mi, hi)
    }//出口时hi = lo + 1,查找区间仅含一个元素A[lo]
    return (e == A[lo]) ? lo : -1;//查找成功时返回对应的秩;否则统一返回-1
}//有多个命中元素时,不能保证返回秩最大者;查找失败时,简单的返回-1,而不能指示失败的位置

template <typename T>//二分查找算法(版本C)
static Rank binSearchC(T* A, T const& e, Rank lo, Rank hi)
{
    while(lo < hi)//每步迭代仅需做一次比较判断，有两个分支
    {
        Rank mi = (lo + hi) >> 1;//以中点为轴
        (e < A[mi]) ? hi = mi : lo = mi + 1;//经过比较后确定深入[lo, mi)或(mi, hi)
    }//成功查找不能提前终止
    return --lo;//循环结束时,lo为大于e的元素的最小秩,故lo - 1即不大于e的元素的最大秩
}//有多个命中元素时,总能保证返回秩最大者;查找失败时,能够返回失败的位置

template <typename T>//Fibonacci查找算法(版本A):在有序向量的区间[lo, hi)内查找元素e,0 <= lo <= hi <= _size
static Rank fibSearch(T* A, T const& e, Rank lo, Rank hi)
{
    Fib fib (hi - lo);//用O(log_phi(n = hi - lo))时间创建Fib数列
    while(lo < hi)//每步迭代可能要做两次比较判断，有三个分支
    {
        while(hi - lo < fib.get())//通过向前顺序查找(分摊O(1))----至多迭代几次?
        {
            fib.prev();
        }
        Rank mi = lo + fib.get() - 1;//确定形如Fib(k) - 1的轴点
        if(e < A[mi])
        {
            hi = mi;//深入前半段[lo, mi)继续查找
        }
        else if(A[mi] < e)
        {
            lo = mi + 1;//深入后半段(mi, hi)继续查找
        }
        else
        {
            return mi;//在mi处命中
        }
    }//成功查找可以提前终止
    return -1;//查找失败
} //有多个命中元素时,不能保证返回秩最大者;失败时，简单的返回-1,而不能指示失败的位置

template <typename T>
struct Increase//函数对象:递增一个T类对象
    {//virtual关键字主要用于声明虚函数（virtual functions）和虚继承（virtual inheritance）
        virtual void operator() (T& e)
        {
            e++;//假设T可直接递增或已重载++
        }
    };

template <typename T>
void increase(Vector<T> &V)
{
    V.traverse(Increase<T>());
}

template <typename T>
void permute(Vector<T>& V)//整体置乱
    {
        for(int i = V.size(); i > 0; i--)//自前向后
        {
            swap(V[i - 1], V[rand() % i]);//V[i - 1)与V[0, i)中某一随机元素交换
        }
    }

void visit(int& i)
{
    std::cout << i <<", ";
}
void visit2(int& i)
{
    std::cout << i <<", ";
}

