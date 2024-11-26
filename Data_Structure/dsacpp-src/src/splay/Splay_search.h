/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

template <typename T> BinNodePosi<T>& Splay<T>::search( const T& e ) { //在伸展树中查找e
   BinNodePosi<T> p = BST<T>::search( e ); //按BST标准算法查找
   _root = p ? splay(p) : _hot ? splay(_hot) : NULL;  //无论成功、失败、树空，被访问的节点将伸展至根
   return _root;
} //与其它BST不同，无论如何，_root都指向最后被访问的节点