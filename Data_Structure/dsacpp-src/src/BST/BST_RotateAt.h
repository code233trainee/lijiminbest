/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * BST节点旋转变换统一算法（3节点 + 4子树），返回调整之后局部子树根节点的位置
 * 注意：尽管子树根会正确指向上层节点（如果存在），但反向的联接须由上层函数完成
 ******************************************************************************************/
template <typename T> BinNodePosi<T> BST<T>::rotateAt( BinNodePosi<T> v ) { //v为非空孙辈节点
   /*DSA*/if ( !v ) { printf ( "\a\nFail to rotate a null node\n" ); exit ( -1 ); }
   BinNodePosi<T> p = v->parent; BinNodePosi<T> g = p->parent;
   switch ( ( IsRChild(*p) << 1 ) | IsRChild(*v) ) { //视p、v的拐向，分四种情况
      case 0b00 : //zig-zig
         p->parent = g->parent; return connect34( v, p, g, v->lc, v->rc, p->rc, g->rc );
      case 0b01 : //zig-zag
         v->parent = g->parent; return connect34( p, v, g, p->lc, v->lc, v->rc, g->rc );
      case 0b10 : //zag-zig
         v->parent = g->parent; return connect34( g, v, p, g->lc, v->lc, v->rc, p->rc );
      default : //0b11 ~ zag-zag
         p->parent = g->parent; return connect34( g, p, v, g->lc, p->lc, v->lc, v->rc );
   }
}