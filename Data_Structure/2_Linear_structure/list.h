#include "listNode.h"//引入列表节点类
#include <iostream>
using namespace std;

template <typename T>
class List//列表模板类
{
    private:
        int _size;//规模
        ListNodePosi(T) header;//头哨兵
        ListNodePosi(T) trailer;//尾哨兵

    //可以在类的内部、派生类（子类）内部访问，但不能在类的对象或派生类的对象中直接访问。
    protected:
        void init()//列表创建时的初始化
        {
            header = new ListNode<T>;
            trailer = new ListNode<T>;
            header->succ = trailer;
            header->pred = NULL;
            trailer->pred = header;
            trailer->succ = NULL;
            _size = 0;//记录规模
        }
        
        int clear()//清除所有节点
        {
            int oldsize = _size;
            while(0 < _size)
            {   
                //auto p = header->succ;
                remove(header->succ);//反复删除首节点，直至列表变空
                //header = p;
            }
            return oldsize;
        }

        void copyNodes(ListNodePosi(T) p, int n)//复制列表中自位置p起的n项
        {
            //p合法，且至少有n-1个真后继节点
            init();//创建头，尾哨兵节点并做初始化
            while(n--)
            {
                insertAsLast(p->data);
                p = p->succ;//将自p起的n项依次作为末节点插入
                //p = p->succ后p已经是下一个节点了
            }
        }

        void merge(ListNodePosi(T)& p, int n, List<T>& L, ListNodePosi(T) q, int m)//归并
        {//有序列表的归并:当前列表中自p起的n个元素,与列表L中自q起的m个元素归并
            ListNodePosi(T) pp = p->pred;//借助前驱(可能是header),以便返回前
            while(0 < m)//在q尚未移出区间之前
            {
                if((0 < n) && (p->data <= q->data))
                {
                    if(q == (p = p->succ))//若p仍在区间内且v(p) <= v(q),则
                    {
                        break;
                        n--;//p归入合并的列表，并替换为其直接后继
                    }
                    else//若p已超出右界或v(q) < v(p),则
                    {
                        insertB ( p, L.remove((q = q->succ)->pred));
                        m--;//将q转移至p之前
                    }
                }
            }
            p = pp->succ;//确定归并后区间的(新)起点
        }

        void mergeSort(ListNodePosi(T) p, int n)//对从p开始连续的n个节点归并排序
        {//valid(p) && rank(p) + n <= size
            if(n < 2)
            {
                return;//若待排序范围已足够小,则直接返回;否则
            }
            int m = n >> 1;//以中点为界
            ListNodePosi(T) q = p;
            for(int i = 0; i < m; i++)//均分列表
            {
                q = q->succ;
            }
            mergeSort(p, m);
            mergeSort(q, n - m);//对前，后子列表分别排序
            merge(p, m, *this, q, n - m);//归并
        }//注意:排序后，p依然指向归并后区间的(新)起点

        void selectionSort(ListNodePosi(T) p, int n)//对从p开始连续的n个节点选择排序
        {
            ListNodePosi(T) head = p->pred;
            ListNodePosi(T) tail = p;
            for(int i = 0; i < n; i++ )
            {
                tail = tail->succ;//待排序区间为(head, tail)
            }
            while(1 < n)//在至少还剩两个结点之前,在待排序区间内
            {
                ListNodePosi(T) max = selectMax(head->succ, n);//找出最大者(歧义时后者优先)
                insertB(tail, remove(max));//将其移至无序区间末尾(作为有序区间新的首元素)
                tail = tail->pred;
                n--;
            }
        }

        void insertionSort(ListNodePosi(T) p, int n)//对从p开始连续的n个节点插入排序
        {
            for(int r = 0; r < n; r++)//逐一为各节点
            {
                insertA(search(p->data, r, p), p->data);//查找适当的位置并插入
                p = p->succ;
                remove(p->pred);//转向下一结点
            }
        }

    public:
        //构造函数
        List()//默认
        {
            init();
            cout << "调用默认构造函数" << endl;
        }

        List(List<T> const& L)//整体复制列表L
        {
            copyNodes(L.first(), L.size());
        }

        List(List<T> const& L, Rank r, int n)//复制列表中自第r项起的n项
        {
            copyNodes(L[r], n);
        }

        List(ListNodePosi(T) p, int n)//复制列表中自位置p起的n项
        {
            copyNodes(p, n);
        }
        //析构函数
        ~List()//释放(包含头，尾哨兵在内的)所有节点
        {
            clear();
            delete header;
            delete trailer;//清空列表，释放头，尾哨兵结点
        }

        //只读访问接口
        Rank size() const//规模
        {
            return _size;
        }
        bool empty() const//判空
        {
            return _size <= 0;
        }

        T& operator[] (Rank r) const//重载，支持循秩访问(效率低)
        {
            ListNodePosi(T) p = first();//从首节点出发
            while(0 < r--)
            {
                p = p->succ;//顺数第r个节点即是
            }
            return p->data;//目标节点，返回其中所存的元素
        }

        ListNodePosi(T) first() const//首节点位置
        {
            return header->succ;
        }
        ListNodePosi(T) last() const//末节点位置
        {
            return trailer->pred;
        }
        bool valid(ListNodePosi(T) p)//判断位置p是否对外合法
        {
            return p && (trailer != p) && (header != p);//将头，尾节点等同于NULL
        }
        int disordered() const;//判断是否已排序
        ListNodePosi(T) find (T const& e) const//无序列表查找
        {
            return find(e, _size, trailer);
        }
        ListNodePosi(T) find(T const& e, int n, ListNodePosi(T) p) const//无序区间查找
        {
            while(0 < n--)
            {
                if(e == (p = p->pred)->data)
                {
                    return p;//逐个比对，直至命中或范围越界
                }
            }
            return NULL;//p越出左边界意味着区间内不含e，查找失败
        }//失败时返回NULL
        ListNodePosi(T) search(T const& e) const//有序列表查找
        {
            return search(e, _size, trailer);
        }
        ListNodePosi(T) search(T const& e, int n, ListNodePosi(T) p) const//有序区间查找
        {
            while(0 <= n--)//对于p的最近的n个前驱，从右向左逐个比较
            {
                if(((p = p->pred)->data) <= e)
                {
                    break;//直至命中，数组越界，或范围越界
                }
            }
            return p;//返回查找终止的位置
        }//失败时，返回区间左边界的前驱(可能是header)----调用者可通过valid()判断成功与否

        ListNodePosi(T) selectMax(ListNodePosi(T) p, int n)//在p及其n-1个后继中选出最大者
        {
            ListNodePosi(T) max = p;//最大者暂定为首节点p
            for(ListNodePosi(T) cur = p; 1 < n; n--)//从首节点p出发，将后续节点逐一与max比较
            {
                if(!lt((cur = cur->succ)->data, max->data))//若当前元素不小于max，则
                {
                    max = cur;//更新最大元素位置记录
                }
            }
            return max;//返回最大结点位置
        }
        ListNodePosi(T) selectMax()//整体最大者
        {
            return selectMax(header->succ, _size);
        }

        //可写访问接口
        ListNodePosi(T) insertAsFirst(T const& e)//将e当作首节点插入
        {
            _size++;
            return header->insertAsSucc(e);
        }
        ListNodePosi(T) insertAsLast(T const& e)//将e当作末节点插入
        {
            _size++;
            return header->insertAsSucc(e);
        }
        ListNodePosi(T) insertA(ListNodePosi(T) p, T const& e)//将e当作p的后继插入(after)
        {
            _size++;
            return p->insertAsPred(e);
        }
        ListNodePosi(T) insertB(ListNodePosi(T) p, T const& e)//将e当作p的前驱插入(befor)
        {
            _size++;
            return p->insertAsPred(e);
        }
        T remove(ListNodePosi(T) p)//删除合法位置p处的节点，返回被删除节点
        {
            T e = p->data;//备份待删除结点的数值(假设T类型可直接赋值)
            p->pred->succ = p->succ;//后继
            p->succ->pred = p->pred;//前驱
            delete p;
            _size--;//释放节点，更新规模
            return e;//返回备份的数值
        }
        void merge(List<T>& L)
        {
            merge(first(), size, L, L.first(), L._size);//全列表归并
        }
        void sort(ListNodePosi(T) p, int n)//列表区间排序
        {
            switch(rand() % 3)
            {
                case 1: insertionSort(p, n); break;//插入排序
                case 2: selectionSort(p, n); break;//选择排序
                case 3: mergeSort(p, n); break;//归并排序
            }
        }
        void sort()
        {
            sort(first(), _size);//列表整体排序
        }

        int deduplicate()//无序去重
        {
            if(_size < 2)
            {
                return 0;//平凡列表自然无重复
            }
            int oldsize = _size;//记录原规模
            ListNodePosi(T) p = header;
            Rank r = 0;//p从首节点开始
            while(trailer != (p = p->succ))
            {
                ListNodePosi(T) q = find(p->data, r, p);//在p的r个(真)前驱中查找雷同者
                q ? remove(q) : r++;//若存在，则删除;否则秩加一
            }//assert:循环过程中的任意时刻，p的所有前驱互不相同
            return oldsize - _size;//列表规模变化，即被删除元素的总数
        }

        int uniquify()//有序去重
        {
            if(_size < 2)
            {
                return 0;//平凡列表自然无重复
            }
            int oldsize = _size;//记录原规模
            ListNodePosi(T) p = first();
            ListNodePosi(T) q;//p为各区段起点，q为其后继
            while(trailer != (q = p->succ))//反复考察紧邻的节点对(p, q)
            {
                if(p->data != q->data)
                {
                    p = q;//若互异,则转向下一区段
                }
                else
                {
                    remove(q);//否则(雷同),删除后者
                }
            }
            return oldsize - _size;//列表规模变化量，即被删除元素总数
        }

        void reverse();//前后倒置(习题)

        //遍历
        void traverse (void(*)(T&))//遍历，依次实施visit操作(函数指针，只读或局部性修改)
        {
            for(ListNodePosi(T) p = header->succ; p != trailer; p = p->succ)
            {
                visit(p->data);
            }
        }
        template<typename VST> //操作器
        void traverse(VST&) //遍历，依次实施visit操作(函数对象，可全局性修改)
        {
            for(ListNodePosi(T) p = header->succ; p != trailer; p = p->succ)
            {
                visit(p->data);
            }
        }
};

template <typename T>
void visit(ListNodePosi(T) p)
{
    cout << p->data + 1 << endl;
}

template <typename T> static bool lt( T* a, T* b ) { return lt( *a, *b ); } // less than
template <typename T> static bool lt( T& a, T& b ) { return a < b; } // less than
template <typename T> static bool eq( T* a, T* b ) { return eq( *a, *b ); } // equal
template <typename T> static bool eq( T& a, T& b ) { return a == b; } // equal

template <typename T>
void print(List<T> a)
{
    for(int i = 0; i < a.size(); i++)
    {
        cout << a[i] << ", ";
    }
    cout << endl;
}

