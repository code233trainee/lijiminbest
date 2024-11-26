/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

template <typename K, typename V> bool Hashtable<K, V>::remove( K k ) { //散列表词条删除算法
   Rank r = probe4Hit( k ); if ( !ht[r] ) return false; //确认目标词条确实存在
   release( ht[r] ); ht[r] = NULL; --N; //清除词条
   removed->set(r); //设置懒惰删除标记
   return true;
}