#include "BinNode.h"
#include "Stack.h"
#include "Queue.h"

template <typename T> 
class BinTree //二叉树模板类
{
    int _size;//规模
    BinNodePosi(T) _root;//根节点
    virtual int updateHeight (BinNodePosi(T) x)//更新节点x的高度
    {
        return x->height = 1 + max (stature(x->lc), stature(x->rc));//具体规则,因树而异
    }
    void updateHeightAbove (BinNodePosi(T) x)//更新节点x及其祖先的高度
    {
        while(x)
        {
            updateHeight(x);
            x = x->parent;//从x出发,覆盖历代祖先。可优化
        }
    }
    public:
        //构造函数
        BinTree() : _size(0), _root(NULL){}
        //析构函数
        ~BinTree()
        {
            if( 0 < _size)
            {
                remove(_root);
            }
        }
        int size() const
        {
            return _size;//规模
        }
        bool empty() const
        {
            return !_root;//判空
        }
        BinNodePosi(T) root() const
        {
            return _root;//树根
        }
        BinNodePosi(T) insertAsRoot(T const& e)//插入e根节点
        {
            _size = 1;
            return _root = new BinNode(T) (e);
        }
        BinNodePosi(T) insertAsLC (BinNodePosi(T) x, T const& e)//e作为x的左孩子(原无)插入
        {
            _size++;
            x->insertAsLC(e);
            updateHeightAbove(x);
            return x->lc;
        }
        BinNodePosi(T) insertAsRC (BinNodePosi(T) x, T const& e)//e作为x的右孩子(原无)插入
        {
            _size++;
            x->insertAsRC(e);
            updateHeightAbove(x);
            return x->rc;
        }
        BinNodePosi(T) attachAsLC (BinNodePosi(T) x, BinTree<T>* &S)//S作为x左子树接入,S本身置空
        {
            if(x->lc = S->_root)
            {
                x->lc->parent = x;//接入
            }
            _size += S->_size;
            updateHeightAbove(x);//更新全树规模与x所有祖先的高度
            S->_root = NULL;
            S->_size = 0;
            release(S);
            S = NULL;
            return x;//释放原树，返回接入位置
        }
        BinNodePosi(T) attachAsRC (BinNodePosi(T) x, BinTree<T>* &S)//S作为x右子树接入
        {
            if(x->rc = S->_root)
            {
                x->rc->parent = x;//接入
            }
            _size += S->_size;
            updateHeightAbove(x);//更新全树规模与x所有祖先的高度
            S->_root = NULL;
            S->_size = 0;
            release(S);
            S = NULL;
            return x;//释放原树，返回接入位置
        }
        int remove (BinNodePosi(T) x)//删除以位置x处节点为根的子树,返回孩子树原先的规模
        {
            FromParentTo(*x) = NULL;//切断来自父节点的指针
            updateHeightAbove(x->parent);//更新祖先高度
            int n = removeAt(x);
            _size -= n;
            return n;//删除子树x，更行规模，返回删除节点总数
        }
        static int removeAt(BinNodePosi(T) x)//删除二叉树中位置x处的节点及其后代，返回被删除节点的数值
        {
            if(!x)
            {
                return 0;//递归基：空树
            }
            int n = 1 + removeAt(x->lc) + removeAt(x->rc);//递归释放左，右子树
            release(x->data);
            release(x);
            return n;//释放被摘除节点，并返回删除节点总数
        }
        BinTree<T>* secede (BinNodePosi(T) x)//将子树x从当前树中摘除,并将其转换为一颗独立子树返回
        {
            FromParentTo (*x) = NULL;//切断来自父节点的指针
            updateHeightAbove(x->parent);//更新原树中所有祖先的高度
            BinTree<T>* S = new BinTree<T>;
            S->_root = x;
            x->parent = NULL;//新树以x为根
            S->_size = x->size();
            _size -= S->_size;
            return S;//更新规模,返回分离出来的子树
        }
        
        template <typename VST> //操作器
        void travLevel (VST& visit)
        {
            if(_root)
            {
                _root->travLevel(visit);//层次遍历
            }
        }
        template <typename VST>

        void travLevel_t(VST& visit)//二叉树层次遍历算法
        {
            Queue<BinNodePosi(T)> Q;//辅助队列
            Q.enqueue(this);//根节点入队
            while(!Q.empty())//队列再次变空之前,反复迭代
            {
                BinNodePosi(T) x = Q.dequeue();
                visit(x->data);//取出队首节点并访问之
                if(HasLChild(*x))
                {
                    Q.enqueue(x->lc);//左孩子入队
                }
                if(HasRChild(*x))
                {
                    Q.enqueue(x->rc);//右孩子入队
                }
            }
        }



        template <typename VST> //操作器
        void travPre(VST& visit)
        {
            if(_root)
            {
                _root->travPre(visit);//先序遍历
            }
        }
        template <typename VST>
        void travPre_R(BinNodePosi(T) x, VST& visit)//二叉树先序遍历算法(递归版#1)
        {
            if(!x) return;
            visit(x->data);
            travPre_R(x->lc, visit);
            travPre_R(x->rc, visit);
        }
        template <typename VST>
        static void visitAlongLeftBranch(BinNodePosi(T) x, VST& visit, Stack<BinNodePosi(T)>& S)
        {
            while(x)
            {
                visit(x->data);//访问当前节点
                S.push(x->rc);//右孩子入栈暂存(可优化:通过判断，避免空的右孩子入栈)
                x = x->lc;//沿左分支深入一层
            }
        }
        template <typename VST>
        void travPre_I2(BinNodePosi(T) x, VST& visit)//二叉树先序遍历法(迭代版#2)
        {
            Stack<BinNodePosi(T)> S;//辅助栈
            while(true)
            {
                visitAlongLeftBranch(x, visit, S);//从当前节点出发，逐批访问
                if(S.empty()) break;//直到栈空
                x = S.pop();//弹出下一批的起点
            }
        }



        template <typename VST> //操作器
        void travIn (VST& visit)
        {
            if(_root)
            {
                root->travIn(visit);//中序遍历
            }
        }
        template <typename VST>
        void travIn_R(BinNodePosi(T) x, VST& visit)//二叉树中序遍历算法(递归版)
        {
            if(!x) return;
            travIn_R(x->lc, visit);
            visit(x->data);
            travIn_R(x->rc, visit);
        }
        static void goAlongLeftBranch (BinNodePosi(T) x, Stack<BinNodePosi(T)>& S)
        {
            while (x)
            {
                S.push(x);
                x = x.lc;//当前节点入栈后随即向左侧分支深入,迭代直到无左孩子
            }
        }
        template <typename VST> 
        void travIn_I1(BinNodePosi(T) x, VST& visit)//二叉树中序遍历算法(迭代版#1)
        {
            Stack<BinNodePosi(T)> S;//辅助栈
            while (true)
            {
                goAlongLeftBranch(x, S);//从当前节点处出发,逐批入栈
                if(S.empty()) break;//直至所有节点处理完毕
                x = S.pop();
                visit(x->data);//弹出栈顶结点并访问之
                x = x->rc;//转向右子树
            }
        }

        BinNodePosi(T) succ()//定位节点v的直接后继
        {
            BinNodePosi(T) s = this;//记录后继的直接变量
            if(rc)//若有右孩子,则直接后继必在右子树中
            {
                while(HasLChild(*s))
                {
                    s = s->lc;//最靠左(最小)的节点
                }
            }
            else//否则,直接后继应是"将当前节点包含于其左子树中的最低祖先",具体地就是
            {
                while (IsRChild(*s))//逆向地沿右向分支,不断朝左上方移动
                {
                    s = s->parent;//最后再朝右上方移动一步,即抵达直接后继(如果存在)
                }
            }
            return s;
        }
        
        template <typename VST>
        void trav_I2(BinNodePosi(T) x, VST& visit)//二叉树的中序遍历算法(迭代版#2)
        {
            Stack<BinNodePosi(T) S;//辅助栈
            while(true)
            {
                if(x)
                {
                    S.push(x);//根节点进栈
                    x = x->lc;//深入遍历左子树
                }
                else if(!S.empty())
                {
                    x = S.pop();//尚未访问的最低祖先节点退栈
                    visit(x->data);//访问该祖先节点
                    x = x->rc;//遍历祖先的右子树
                }
                else
                {
                    break;//遍历完成
                }
            }
        }
        template <typename VST>
        void travIn_I3(BinNodePosi(T) x, VST& visit)//二叉树中序遍历算法(迭代版#3)
        {
            bool backtrack = false;//前一步是否刚从右子树回溯----省去栈，仅O(1)辅助空间
            while(true)
            {
                if(!backtrack && HasLChild(*x))//若有左子树且不是刚刚回溯,则
                {
                    x = x->lc;//深入遍历左子树
                }
                else//否则----无左子树或刚刚回溯(相当于无左子树)
                {
                    visit(x->data);//访问该节点
                    if(HasRChild(*x))//若其右子树非空,则
                    {
                        x = x->rc;//深入右子树继续遍历
                        backtrack = false;//并关闭回溯标志
                    }
                    else//若右子树空,则
                    {
                        if(!(x = x->succ())) break;//回溯(含抵达末节点时的退出返回)
                        backtrack = true;//并设置回溯标志
                    }
                }
            }
        }

    
        template <typename VST> //操作器
        void travPost(VST& visit)
        {
            if(_root)
            {
                _root->travPost(visit);//后序遍历
            }
        }
        template <typename VST>
        void travPost_R(BinNodePosi(T) x, VST& visit)//二叉树后序遍历算法(递归版)
        {
            if(!x) return;
            travPost_R (x->lc, visit);
            travPost_R (x->rc, visit);
            visit(x->data);
        }
        static void gotoHLVFL (Stack<BinNodePosi(T)>& S)//沿途所遇节点依次入栈
        {
            while(BinNodePosi(T) x = S.top())//自顶而下，反复检查当前节点(即栈顶)
            {//赋值语句会执行，将右侧的值赋给左侧的变量。
             //赋值语句的结果（即被赋的值）将作为while循环的条件被评估。
                if(HasLChild(*x))//尽可能向左
                {
                    if(HasRChild(*x))//宏是为直接的对象实例设计的，而不是指针。所以在这里会进行解引用，解引用之后才是一个类对象
                    {
                        S.push(x->rc);//若有右孩子，优先入栈
                    }
                    S.push(x->lc);//然后才转至左孩子
                }
                else//实在不得已
                {
                    S.push(x->rc);//才向右
                }
            }
            S.pop();//返回之前，弹出栈顶的空节点
        }
        template <typename VST> 
        void travPost_I (BinNodePosi(T) x, VST& visit)//二叉树的后序遍历(迭代版)
        {
            Stack<BinNodePosi(T)> S;//辅助栈
            if(x)
            {
                S.push(x);//根节点入栈
            }
            while(!S.empty())
            {
                if(S.top() != x->parent)//若栈顶非当前节点之父(则必为其右兄),此时需
                {
                    gotoHLVFL(S);//在以其右兄为根之子树中，找到HLVFL(相当于递归深入其中)
                }
                x = S.pop();
                visit(x->data);//弹出栈顶(即前一节点之后继),并访问之
            }
        }


        bool operator< (BinTree<T> const& t)//比较器
        {
            return _root && t._root && lt (_root, t._root);
        }
        bool operator> (BinTree<T> const& t)
        {
            return _root && t._root && (*_root > *(t._root));
        }
        bool operator== (BinTree<T> const& t)//判等器
        {
            return _root && t._root && (_root == t._root);
        }
};