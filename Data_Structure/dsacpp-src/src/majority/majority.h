/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

template <typename T> bool majority( Vector<T> A, T& maj ) { //众数查找算法：T可比较可判等
   maj = majCandidate( A ); //必要性：选出候选者maj
   return majCheck( A, maj ); //充分性：验证maj是否的确当选
}
