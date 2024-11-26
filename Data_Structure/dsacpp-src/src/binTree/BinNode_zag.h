/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

template <typename T> BinNodePosi<T> BinNode<T>::zag() { //ÄæÊ±ÕëÐý×ª
   BinNodePosi<T> v = rc; if ( !v ) return this;
   v->parent = parent;
   if ( v->parent )
      ( ( this == v->parent->lc ) ? v->parent->lc : v->parent->rc ) = v;
   rc = v->lc; if ( rc ) rc->parent = this;
   v->lc = this; parent = v;
   updateHeight(); v->updateHeight();
   return v;
}
