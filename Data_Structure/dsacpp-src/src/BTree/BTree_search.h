/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

template <typename T> BTNodePosi<T> BTree<T>::search( const T& e ) { //在B-树中查找关键码e
   _hot = NULL;
   for ( BTNodePosi<T> v = _root; v; ) { //从根节点出发，逐层查找
      Rank r = v->key.search( e ); //在当前节点中，找到不大于e的最大关键码
      if ( ( -1 != r ) && ( e == v->key[r] ) ) return v; //成功；否则...
      _hot = v; v = v->child[r + 1]; //转入对应的孩子节点（I/O）
   } //这里在向量key内是二分查找，但对通常的_m，改为顺序查找效率反而更高
   return NULL; //失败：最终抵达外部节点
}
