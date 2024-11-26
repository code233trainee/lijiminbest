#include "list.h"
using namespace std;

template <typename T> 
class Queue : public List<T> //队列模板类(继承List原有接口)
{
    public://size(),empty()以及其它开放接口均可直接沿用
        void enqueue (T const& e)
        {
            insertAsLast(e);//入队:尾部插入
        }
        T dequeue ()
        {
            return remove(first());//出队:首部删除
        }
        T& front()
        {
            return first()->data;//队首
        }
};


//银行服务模拟
struct Customer//结构体默认公有
{
    int window;
    unsigned int time;//顾客类；所属窗口(队列)，服务时长
};

int bestWindow(Queue<Customer> windows[], int nwin)
{
    int minSize = windows[0].size(), optiWin = 0;//最优队列(窗口)
    for(int i = 1; i < nwin; i++)//在所有窗口中
    {
        if(minSize > windows[i].size())//挑选出
        {
            minSize = windows[i].size();
            optiWin = i;//队列最短者
        }
    }

    return optiWin;//返回
}

void simulate (int nwin, int servTime)//按指定窗口数，服务总时间模拟银行业务
{
    Queue<Customer>* windows = new Queue<Customer>[nwin];//为每一个窗口创建一个队列
    for(int now = 0; now < servTime; now++)//在下班之前，每隔一个单位时间
    {
        if(rand() % (1 + nwin))//新顾客以nwin/(nwin + 1)的概率到达
        {
            Customer c;
            c.time = 1 + rand() % 98;//新顾客到达，服务时长随机确定
            c.window = bestWindow(windows, nwin);//找出最佳(最短)的服务窗口
            windows[c.window].enqueue(c);//新顾客加入对应的队列
        }
        for(int i = 0; i < nwin; i++)
        {
            if(!windows[i].empty())//各非空队列
            {
                if(--windows[i].front().time <= 0)//队首顾客的服务时长减少一个单位
                {
                    windows[i].dequeue();//服务完毕的顾客出列,由后继顾客接替
                }
            }
        }
    }//for
    delete [] windows;//释放所有队列(此前，~List()会自动清空队列)
}

