/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

extern int s_lo, s_hi;

int gs_LS( int A[], int n ) { //扫描策略：O(n)
   int gs = A[0], s = 0, i = n, j = n;
   while ( 0 < i-- ) { //在当前区间[i,j)内
      s += A[i]; //递增地累计总和
      if ( gs < s ) { gs = s; s_lo = i; s_hi = j; } //择优、更新
      if ( s <= 0 ) { s = 0; j = i; } //剪除负和后缀
   }
   return gs;
}
