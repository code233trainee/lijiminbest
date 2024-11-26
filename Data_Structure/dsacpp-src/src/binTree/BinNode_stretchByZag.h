/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

//通过zag旋转调整，将BST子树x拉伸成最左侧通路
template <typename T> void stretchByZag( BinNodePosi<T>& x ) {
   if ( !x ) return;
   /*DSA*/int c = 0; //记录旋转次数
   BinNodePosi<T> r = x; while ( r->rc ) r = r->rc; //最大节点，必是子树最终的根
   BinNodePosi<T> v = x; while ( v->lc ) v = v->lc; //从最左侧通路的末端出发
   while ( v != r ) //逐层处理，直到抵达子树的根
      if ( v == v->zag() ) //以v为轴做zag旋转（同时更新高度）
         ( v = v->parent )->updateHeight(); //直至没有右孩子
      /*DSA*/else
         /*DSA*/c++;
   v->updateHeightAbove();
   /*DSA*/ printf( "size = %d, height = %d, #zag = %d\n", r->size(), r->height, c );
   x = r;
}
