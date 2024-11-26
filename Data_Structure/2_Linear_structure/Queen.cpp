#include "Vector.h"
template <typename T>
class Stack: public Vector<T>  //将向量的首/末端作为栈底/顶
{
    public://size(),empty()以及其它开放接口，均可直接沿用
        void push(T const& e)//入栈，等效于将新元素作为向量的末尾元素插入
        {
            insert(size(), e);
        }
        T pop()//出栈:等效于删除向量的末元素
        {
            return remove(size() - 1);
        }
        T& top()//取顶:直接返回向量的末元素
        {
            return (*this) [size() - 1];
        }
};

//默认公有
struct Queen //皇后类
{
    int x, y;//皇后在棋盘上的位置坐标
    Queen(int xx = 0, int yy = 0) : x(xx), y(yy)
    {

    };

    bool operator== (Queen const& q) const//重载判等操作符,以检测不同皇后之间可能的冲突
    {
        return  (x == q.x)//行冲突
                || (y == q.x)//列冲突
                || (x + y == q.x + q.y)//沿正对角线冲突
                || (x - y == q.x - q.y);//沿反对角线冲突
    }
    bool operator!= (Queen const& q) const//重载不等操作符
    {
        return !(*this == q);
    }
};

void placeQueen(int N)//N皇后算法(迭代版):采用试探回溯的策略,借助栈记录查找的结果
{
    Stack<Queen> solu;//存放（部分）解的栈
    Queen q (0,0);//从原点出发
    do
    {
        if(N <= solu.size() || N <= q.y)//若已出界,则
        {
            q = solu.pop();
            q.y++;//回溯一行,并继续试探下一列
        }
        else//否则试探下一行
        {
            while((q.y < N) && (0 <= solu.find(q)))//通过与已有皇后的比对
            {
                q.y++;
                
            }
        }
    } while ((0 < q.x) || (q.y < N));
    
}