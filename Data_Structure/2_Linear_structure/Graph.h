#include "Queue.h"
#include "Stack.h"
typedef enum{UNDISCOVERED, DISCOVERED, VISITED} VStatus; //顶点状态
typedef enum{UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD} EType; //边在遍历树中所属的类型

template <typename Tv, typename Te> //顶点类型，边类型
class Graph //图Graph模板类
{
    private:
        void reset()//所有的顶点，边的辅助信息复位
        {
            for(int i = 0; i < n; i++)//所有顶点的
            {
                status(i) = UNDISCOVERED;
                dTime(i) = fTime(i) = -1;//状态，时间标签
                parent(i) = -1;
                priority(i) = INT_MAX;//(在遍历树中的)父亲节点,优先级数
                for(int j = 0; j < n; j++)//所有边的
                {
                    if(exists(i, j))
                    {
                        type(i, j) = UNDETERMINED;//类型
                    }
                }
            }
        }
    void BFS(int v, int& clock)//(连通域)广度优先搜索
    {
        Queue<int> Q;//引入辅助队列
        status (v) = DISCOVERED;
        Q.enqueue(v);//初始化起点
        while(!Q.empty())//在Q变空之前，不断
        {
            int v = Q.dequeue();
            dTime(v) = ++clock;//取出队首顶点v
            for(int u = firstNbr(v); -1 < u; u = nextNbr(v, u))//枚举v的所有邻居u
            {
                if(UNDISCOVERED == status(u))//若u尚未被发现
                {
                    status(u) = DISCOVERED;
                    Q.enqueue(u);//发现该顶点
                    type(v, u) = TREE;
                    parent(u) = v;//引入树边支撑树
                }
                else//若u已经被发现，或者甚至已经访问完毕
                {
                    type(v, u) = CROSS;//将(v, u)归类于跨边
                }
            }
            status(v) = VISITED;//至此，当前顶点访问完毕
        }
    }
    void DFS(int v, int& clock)//(连通域)深度优先搜索算法
    {
        dTime(v) = ++clock;
        status(v) = DISCOVERED;//发现当前顶点v
        for(int u = firstNbr(v); -1 < u; u = nextNbr(v, u))//枚举v的所有邻居
        {
            switch (status(u))//并视其状态分别处理
            {
                case UNDISCOVERED: //u尚未发现，意味着支撑树可在此拓展
                    type(v, u) = TREE;
                    parent(u) = v;
                    DFS (u, clock);
                    break;
                case DISCOVERED: //u已经被发现但是尚未访问完毕，应属被后代指向的祖先
                    type(v, u) = BACKWARD;
                    break;
                default: //u已访问完毕(VISITED, 有向图)，则视承袭关系分为前向边或跨边
                    type(v, u) = (dTime(v) < dTime(u)) ? FORWARD : CROSS;
                    break;
            }
        }
        status(v) = VISITED;
        fTime(v) = ++clock;//至此，当前顶点v方告访问完毕
    }

#define hca(x) (fTime(x)) //利用此处闲置的fTime[]充当hca[]
    void BCC(int v, int& clock, Stack<int>* S)//(联通域)基于DFS的双连通分量分解算法
    {
        hca(v) = dTime(v) = ++clock;
        status(v) = DISCOVERED;
        S.push(v);//v被发现并入栈
        for(int u = firstNbr(v); -1 < u; u = nextNbr(v, u))//枚举v的所有邻居u
        {
            switch(status(u)) //并视u的状态分别处理
            {
                case UNDISCOVERED:
                    parent(u) = v;
                    type(v, u) = TREE;
                    BCC(u, clock, S);//从顶点u处深入
                    if(hca(u) < dTime(v))//遍历返回后，若发现u(通过后向边)可指向v的真祖先
                    {
                        hca(v) = min(hca(v), hca(u))//则v亦必如此
                    }
                    else//否则，以v为关节点(u以下即是一个BCC，且其中顶点此时正集中于栈S的顶部)
                    {
                        while(v != S.pop());//依次弹出当前BCC中的节点，亦可根据实际需求转存至其他结构
                        S.push(v);//最后一个顶点(关节点)重新入栈----分摊不足一次
                    }
                    break;
                case DISCOVERED:
                    type(v, u) = BACKWARD; //标记(v, u),并按照"越小越高"的准则
                    if(u != parent(v))
                    {
                        hca(v) = min(hca(v), dTime(u));//更新hca(v)
                    }
                    break;
                default: //VISITED (digraphs only)
                    type(v, u) = (dTime(v) < dTime(u)) ? FORWARD : CROSS;
                    break;
            }
        }
        status(v) = VISITED;//对v的访问结束
    }
#undef hca

    bool TSort(int v, int& clock, Stack<Tv>* S)//(连通域)基于DFS的拓扑排序算法
    {
        dTime(v) = ++clock;
        status(v) = DISCOVERED;//发现顶点v
        for(int u = firstNbr(v); -1 < u; u = nextNbr(v, u))//枚举v的所有邻居u
        {
            switch(status(u))
            {
                case UNDISCOVERED:
                    parent(u) = v;
                    type(v, u) = TREE;
                    if(!TSort(u, clock, S))//从顶点u处出发深入搜索
                    {
                        return false;//若u及其后代不能拓扑排序(则全图亦必如此)，故返回并报告
                    }
                    break;
                case DISCOVERED:
                    type(v, u) = BACKWARD;//一旦发现后向边(非DAG)，则
                    return false;//不必深入，故返回并报告
                default: //VISITED (digraphs only)
                    type(v, u) = (dTime(v) < dTime(u)) ? FORWARD : CROSS;
                    break;
            }
        }
        status(v) = VISITED;
        S->push(vertex(v));//顶点被标记为VISITED时,随时入栈
        return true;//v及其后代可以拓扑排序
    }
    template <typename PU> 
    void PFS(int s, PU prioUpdater)//(连通域)优先级搜索框架
    {//
        priority(s) = 0;
        status(s) = VISITED;
        parent(s) = -1;//初始化，起点s加至PFS树中
        while(1) //将下一顶点和边加至PFS树中
        {
            for(int w = firstNbr(s); -1 < w; w = nextNbr(s, w))//枚举s的所有邻居w
            {
                prioUpdater(this, s, w);//更新顶点w的优先级及其父顶点
            }
            for(int shortest = INT_MAX, w = 0; w < n; w++)
            {
                if(UNDISCOVERED == status(w))//从尚未加入遍历树的顶点中
                {
                    if(shortest > priority(w))//选出下一个
                    {
                        shortest = priority(w);
                        s = w;//优先级最高的顶点s
                    }
                }
            }
            if(VISITED == status(s))
            {
                break;//直至所有顶点均已加入
            }
            status(s) = VISITED;
            type(parent(s), s) = TREE;//将s及与其父的联边加入遍历树
        }
    }
    //通过定义具体的优先级更新策略prioUpdater,即可实现不同的算法功能
    public:
    //顶点
        int n;//顶点个数
        virtual int insert(Tv const&) = 0;//插入顶点，返回编号(后面跟着=0，说明这是一个纯虚函数)
        virtual Tv remove(int) = 0;//删除顶点及其关联边，返回该顶点信息
        virtual Tv& vertex(int) = 0;//顶点v的数据(该顶点的数据确实存在)
        virtual int inDegree(int) = 0;//顶点v的入度(该顶点的确实存在)
        virtual int outDegree(int) = 0;//顶点v的出度(该顶点的确实存在)
        virtual int firstNbr(int) = 0;//顶点v的首个邻接顶点
        virtual int nextNbr(int, int) = 0;//顶点v的(相对于顶点j的)下一邻接顶点
        virtual VStatus& status(int) = 0;//顶点v的状态
        virtual int& dTime(int) = 0;//顶点v的时间标签dTime
        virtual int& fTime(int) = 0;//顶点v的时间标签fTime
        virtual int& parent (int) = 0;//顶点v在遍历树中的父亲
        virtual int& priority(int) = 0;//顶点v在遍历树中的优先级数
    //边：这里约定，无向边均统一转化为方向互逆的一对有向边，从而将无向图视作有向图的特例
        int e;//总边数
        virtual bool exists(int, int) = 0;//边(v, u)是否存在
        virtual void insert(Te const&, int, int, int) = 0;//在顶点v和u之间插入权重为w的边e
        virtual Te remove(int, int) = 0;//删除顶点v和u之间的边e,返回该边信息
        virtual EType& type(int, int) = 0;//边(v, u)的类型
        virtual Te& edge(int, int) = 0;//边(v, u)的数据(该边的确存在)
        virtual int& weight(int, int) = 0;//边(v, u)的权重
    //算法
        void bfs(int s)//广度优先搜索算法
        {
            reset();
            int clock = 0;
            int v = s;//初始化
            do //逐一检查所有顶点
            {
                if(UNDISCOVERED == status(v)) //一旦遇到尚未发现的顶点
                {
                    BFS(v, clock);//即从该顶点出发启动一次BFS
                }
            }while(s != (v = (++v % n)));//按序号查找，不重不漏
        }
        void dfs(int s)//深度优先搜索算法
        {
            reset();
            int clock = 0;
            int v = s;//初始化
            do //逐一检查所有顶点
            {
                if(UNDISCOVERED == status(v))//一旦遇到尚未发现的顶点
                {
                    DFS(v, clock);//即从该顶点出发启动一次DFS
                }
            } while ( s != (v = ( ++v % n )));//按序号检查,故不重不漏
        }
        void bcc(int s)//基于DFS的双连通分量分解算法
        {
            reset();
            int clock = 0;
            int v = s;
            Stack<int> S;//栈S用以记录已访问的顶点
            do
            {
                if(UNDISCOVERED == status(v))//一旦发现未发现的顶点(新连通分量)
                {
                    BCC(v, clock);//即从该顶点出发启动一次BCC
                    S.pop();//遍历返回后，弹出栈中最后一个顶点----当前连通域的起点
                }
            } while (s != (v = (++v % n)));
            
        }
        Stack<Tv>* tSort(int s)//基于DFS的拓扑排序算法
        {
            reset();
            int clock;
            int v = s;
            Stack<Tv>* S = new Stack<Tv>;//用栈记录排序顶点
            do
            {
                if(UNDISCOVERED == status(v))
                {
                    if(!TSort(v, clock, S))//clock并非必须
                    {
                        while(!S->empty())//任一连通域(亦即整图)非DAG
                        {
                            S->pop();
                            break;//则不必继续计算，故直接返回
                        }
                    }
                }
            } while (!S->empty());
            return S;//若输入为DAG，则S内各顶点自顶向底排序; 否则(不存在拓扑排序)，S空
        }
        // void prim(int);//最小支撑树Prim算法
        // void dijkstra(int);//最短路径Dijkstra算法
        template <typename PU>
        void pfs(int s, PU prioUpdater)//优先级搜索框架
        {
            reset();
            int v = s;//初始化
            do
            {//逐一检查所有顶点
                if(UNDISCOVERED == status(v)) //一旦遇到尚未发现的顶点
                {
                    PFS(v, prioUpdater);//即从该顶点出发启动一次PFS
                }
            } while (s != (v = (++v % n)));//按序号检查，故不重不漏
            
        }
};



