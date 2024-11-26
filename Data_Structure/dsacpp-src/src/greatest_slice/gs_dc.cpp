/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

/*DSA*/#include <cstdlib>
/*DSA*/#include "_share/util.h"

extern int s_lo, s_hi;

int gs_DC( int A[], int lo, int hi ) { //分治策略：O(n*logn)
   if ( hi - lo < 2 ) return A[lo];
   int mi = (lo + hi) / 2;

   int gsL = A[mi-1], sL = 0, i = mi; //枚举
   while ( lo < i-- ) //所有[i, mi)类区段
      if ( gsL < (sL += A[i]) ) gsL = sL;

   int gsR = A[mi], sR = 0, j = mi-1; //枚举
   while ( ++j < hi ) //所有[mi, j)类区段
      if ( gsR < (sR += A[j]) ) gsR = sR; //择优、更新

   return max( gsL + gsR, max( gs_DC( A, lo, mi ), gs_DC( A, mi, hi ) ) ); //递归
}