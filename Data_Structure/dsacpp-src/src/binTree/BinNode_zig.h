/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

template <typename T> BinNodePosi<T> BinNode<T>::zig() { //Ë³Ê±ÕëÐý×ª
   BinNodePosi<T> v = lc; if ( !v ) return this;
   v->parent = parent;
   if ( v->parent )
      ( ( this == v->parent->rc ) ? v->parent->rc : v->parent->lc ) = v;
   lc = v->rc; if ( lc ) lc->parent = this;
   v->rc = this; parent = v;
   updateHeight(); v->updateHeight();
   return v;
}
