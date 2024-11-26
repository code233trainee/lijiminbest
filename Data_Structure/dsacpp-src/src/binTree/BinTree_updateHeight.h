/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

template <typename T> Rank BinNode<T>::updateHeight() //更新当前节点高度
   { return height = 1 + max( stature( lc ), stature( rc ) ); } //具体规则，因树而异

template <typename T> void BinNode<T>::updateHeightAbove() //更新当前节点及其祖先的高度
   { for ( BinNodePosi<T> x = this; x; x = x->parent ) x->updateHeight(); } //可优化
