#pragma once

#define BinNodePosi(T) BinNode<T>* //节点位置
#define stature(p) ((p) ? (p)->height : -1 ) //节点高度(与“空树高度为-1”的约定相统一)
typedef enum {RB_RED, RB_BLACK} RBColor; //节点颜色

/**************************************************************************************************************
*BinNode状态与性质的判断
***************************************************************************************************************/
#define IsRoot(x) ( ! ( (x).parent ))
#define IsLChild(x) (! IsRoot(x) && (&(x) == (x).parent->lc))//单个&代表取地址，在这里比较指针(判断x是否为左节点)
#define IsRChild(x) (! IsRoot(x) && (&(x) == (x).parent->rc))//判断x是否为右节点
#define HasParent(x) (!IsRoot(x))//只要不为根节点就有父节点
#define HasLChild(x) ((x).lc)//只要不为空就是true
#define HasRChild(x) ((x).rc)
#define HasChild(x) (HasLChild(x) || HasRChild(x))//至少拥有一个孩子
#define HasBothChild(x) (HasLChild(x) && HasRChild(X))//同时拥有两个孩子
#define IsLeaf(x) (!HasChild(x))

/**************************************************************************************************************
*与BinNode具有特定关系的节点及指针
***************************************************************************************************************/
#define sibling(p) /*兄弟*/ \
    (IsLChild(*(p) ? (p)->parent->rc : (p)->parent->lc ))

#define uncle(x) /*叔*/ \
    (IsLChild(*((x->parent )) ? (x)->parent->parent->rc : (x)->parent->parent->lc))

#define FromParentTo(x) /*来自父亲的引用*/ \
    (IsRoot(x) ? _root : (IsLChild(x) ? (x).parent->lc : (x).parent->rc))


template <typename T> 
struct BinNode //二叉树节点模板类(struct默认public)
{//成员(为简化描述起见统一开放)
    T data;//数值
    BinNodePosi(T) parent;//父节点
    BinNodePosi(T) lc;//左孩子
    BinNodePosi(T) rc;//右孩子
    int height;//高度(通用)
    int npl;//Null Path Length (左式堆，也可以直接用height代替)
    RBColor Color;//颜色(红黑树)

    //构造函数
    BinNode() : 
        parent(NULL), lc(NULL), rc(NULL), height(0), npl(1), color(RB_RED){}
    BinNode(T e, BinNodePosi(T) p = NULL, BinNodePosi(T) lc = NULL, BinNodePosi(T) rc = NULL, int h = 0, int l = 1, RBColor c = RB_RED) :
        data(e), parent(p), lc(lc), rc(rc), height(h), npl(l), color(c) {}

    //操作接口
    int size();//统计当前节点后代总数,亦即以其为根的子树的规模
    BinNodePosi(T) insertAsLC (T const& e)//作为当前节点的左孩子插入新节点
    {
        return lc = new BinNode(e, this);//将e作为当前节点的左孩子插入二叉树
    }
    BinNodePosi(T) insertAsRC (T const& e)//作为当前节点的右孩子插入新节点
    {
        return rc = new BinNode(e, this);//将e作为当前节点的右孩子插入二叉树
    }
    BinNodePosi(T) succ();//去当前节点的直接后继
    template <typename VST> void travLevel (VST&);//子树层次遍历
    template <typename VST> void travPre (VST&);//子树先序遍历
    template <typename VST> void travIn (VST& visit)//子树中序遍历
    {
        switch(rand() % 5)
        {
            case 1: travIn_I1 (this, visit); break;//迭代版#1
            case 2: travIn_I2 (this, visit); break;//迭代版#2
            case 3: travIn_I3 (this, visit); break;//迭代版#3
            case 4: travIn_I4 (this, visit); break;//迭代版#4
            default: travIn_R (this, visit); break;//递归版
        }
    }
    template <typename VST> void travPost (VST&);//子树后序遍历

    //比较器，判等器
    bool operator< (BinNode const& bn) { return data < bn.data; }//小于
    bool operator> (BinNode const& bn) { return data > bn.data; }//大于
    bool operator== (BinNode const& bn) { return data < bn.data; }//等于
};