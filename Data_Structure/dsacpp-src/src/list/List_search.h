/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

template <typename T> //在有序列表内节点p（可能是trailer）的n个真前驱中，找到不大于e的最后者
ListNodePosi<T> List<T>::search( T const& e, Rank n, ListNodePosi<T> p ) const {
   do { //初始有：0 <= n <= rank(p) < _size；此后，n总是等于p在查找区间内的秩
      p = p->pred; n--;  //从右向左  /*DSA*/ ( -1 == n ) ? printf( " -->header" ) : printf( " -->%4d", p->data );
   } while ( ( -1 != n ) && ( e < p->data ) ); //逐个比较，直至越界或命中  /*DSA*/  printf ( "\n" );
   return p;  //返回最终停止的位置
} //失败时返回区间左边界的前驱（可能是header）——调用者可据此判断查找是否成功