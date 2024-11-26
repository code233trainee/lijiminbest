/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

template <typename T> BinNodePosi<T> BST<T>::insert( const T& e ) { //将关键码e插入BST树中
   BinNodePosi<T>& x = search( e ); //通过查找
   if ( x ) return x; //确认目标不存在，并设置_hot
   x = new BinNode<T>( e, _hot ); //在x处创建新节点，以_hot为父
   _size++; //更新全树规模
   x->updateHeightAbove(); //更新x及其历代祖先的高度
   return x; //新插入的节点，必为叶子
} //无论e是否存在于原树中，返回时总有x->data == e
