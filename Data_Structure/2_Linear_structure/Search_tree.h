#include "Binary_tree.h"
template <typename K, typename V> 
struct Entry //词条模板类
{
    K key;//关键码
    V value;//数值
    Entry (K k = K(), V v = V()) : Key(k), value(v){};//默认构造函数
    Entry (Entry<K, V> cosnt& e) : key(e.key), value(e.value) {};//基于克隆的构造函数
    bool operator< (Entry<K, V> cosnt& e)
    {
        return key < e.key; //比较器：小于
    }
    bool operator> (Entry<K, V> cosnt& e)
    {
        return key > e.key; //比较器：大于
    }
    bool operator== (Entry<K, V> cosnt& e)
    {
        return key == e.key; //判等器：等于
    }
    bool operator!= (Entry<K, V> cosnt& e)
    {
        return key != e.key; //判等器：不等于
    }
};

template <typename T> 
class BST : public BinTree<T> //由BinTree派生BST模板类
{
    protected:
        BinNodePosi(T) _hot; //"命中"节点的父亲
        BinNodePosi(T) connect34 ( //按照"3 + 4"结构,联接3个节点及四颗子树
            BinNodePosi(T) a, BinNodePosi(T) b, BinNodePosi(T) c,
            BinNodePosi(T) T0, BinNodePosi(T) T1, BinNodePosi(T) T2, BinNodePosi(T) T3
        ){
            a->lc = T0; if(T0) T0->parent = a;
            a->rc = T1; if(T1) T1->parent = a; updateHeight(a);
            c->lc = T2; if(T2) T2->parent = c;
            c->rc = T3; if(T3) T3->parent = c; updateHeight(c);
            b->lc = a; a->parent = b;
            b->rc = c; c->parent = b; updateHeight(b);
            return b; //该子树的根节点
        }

        /***********************************************************************
        *BST节点旋转变换统一算法(3节点 + 4子树)，返回调整之后局部子树根节点的位置 
        * 注意：尽管子树根会正确的指向上层节点(如果存在)，但反向的联接需由上层函数完成
        ************************************************************************/
       //zig(顺时针)，zag(逆时针)
        BinNodePosi(T) rotateAt (BinNodePosi(T) v) //对及其父亲，祖父做统一旋转调整,v为非空孙辈节点
        {
            BinNodePosi(T) p = v->parent;
            BinNodePosi(T) g = p->parent;
            if( IsLChild(*p) )//zig
            {
                if( IsLChild(*v) )//zig-zig
                {
                    p->parent = g->parent;//向上联接
                    return connect34(v, p, g, v->lc, v->rc, p->rc, g->rc);
                }
                else//zig-zag
                {
                    v->parent = g->parent;//向上联接
                    return connect34(p, v, g, p->lc, v->lc, v->rc, g->rc);
                }
            }
            else//zag
            {
                if( IsRChild(*v) )//zag-zag
                {
                    p->parent = g->parent;//向上联接
                    return connect34(g, p, v, g->lc, v->lc, v->rc, g->rc);
                }
                else//zag-zig
                {
                    v->parent = g->parent;//向上联接
                    return connect34(g, v, p, g->lc, v->lc, v->rc, g->rc);
                }
            }
        }

    public:
        virtual BinNodePosi(T) & search (const T& e) //查找
        {
            return searchIn(root(), e, _hot = NULL);//返目标节点位置的引用，以便后续插入，删除操作
        }

        virtual BinNodePosi(T) insert (const T& e) //插入
        {//将关键码e插入bst树中
            BinNodePosi(T) & x = search(e);
            if(x)
            {
                return x;//确认目标不存在(留意对_hot的设置)
            }
            x = new BinNode<T> (e, _hot); //创建新节点x:以e为关键码,以_hot为父
            _size++; //更新全树规模
            updateHeightAbove (x); //更新x及其历代祖先的高度
            return x;//新插入的节点必为叶子
        }//无论e是否存在于原树中，返回时总有x->data == e

        virtual bool remove (const T& e) //删除关键码e
        {
            BinNodePosi(T) & x = search(e);
            if(!x)
            {
                return false;//确认目标存在
            }
            removeAt (x, _hot);
            _size--;//实施删除
            updateHeightAbove(_hot); //更新_hot及其历代祖先的高度
            return true;
        }//删除成功与否，由返回值指示

        static BinNodePosi(T) removeAt (BinNodePosi(T) & x, BinNodePosi(T) & hot)
        {
            BinNodePosi(T) w = x;//实际被摘除的结点，初值同x
            BinNodePosi(T) succ = NULL; //实际被摘除结点的接替者
            if(!HasLChild(*x))//若*x的左子树为空，则可 (*x: 解引用指针)[注:(*x).lc与x->lc是等价的]
            {//直接将*x替换为其右子树
                succ = x = x->lc;
            }
            else if(!HasRChild(*x))//若右子树为空,则可
            {
                succ = x = x->lc; //对称地处理----注意:此时succ != NULL
            }
            else //若左右子树均存在，则选择x的直接后继作为实际被摘除点,为此需要
            {
                w = w->succ(); //(在右子树中)找到*x的直接后继*w
                swap(x->data, w->data); //交换*x和*w的数据元素
                BinNodePosi(T) u = w->parent;
                ((u == x) ? u->rc : u->lc) = succ = w->rc; //隔离节点*w
            }
            hot = w->parent; //记录实际被删除节点的父亲
            if(succ)
            {
                succ->parent = hot; //并将被删除接节点的接替者与hot相联
            }
            release (w->data);
            release (w);
            return succ;//释放被摘除节点，返回接替者
        }

        static BinNodePosi(T) & searchIn (BinNodePosi(T) & v, const T& e, BinNodePosi(T) & hot)
        {
            if(!v || (v->data == e))
            {
                return v; //递归基:在节点v(或假想的通配节点处)命中
            }
            hot = v; //一般情况:先记下当前节点,然后再
            return searchIn(((e < v->data) ? v->lc : v->rc), e, hot); //深入一层,递归查找
        }//返回时，返回值指向命中节点(或假想的通配哨兵)，hot指向其父亲(退化时为初始值null)
};