/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#include "Bitmap/Bitmap.h" //����Bitmap�ṹ

/******************************************************************************************
 * ɸ�����������ҳ�С��n����������
 * ��ѭ��ÿ�˵���O(n/i)������ѭ����������������n/ln(n)�ˣ��ۼƺ�ʱ����
 *       n/2 + n/3 + n/5 + n/7 + n/11 + ...
 *    <  n/2 + n/3 + n/4 + n/6 + n/7 + ... + n/(n/ln(n))
 *    =  O(n(ln(n/ln(n)) - 1))
 *    =  O(nln(n) - nln(ln(n)) - 1)
 *    =  O(nlog(n))
 * ����ʵ���У���ѭ������㡢��ѭ�����յ㶼���Ż�
 ******************************************************************************************/
/*DSA*/ #include "_share/util.h"

void Eratosthenes( Rank n, char* file ) {
   Bitmap B( n ); B.set( 0 ); B.set( 1 ); // 0��1����������
   for ( Rank i = 2; i * i < n; i++ ) //�����
      if ( !B.test( i ) ) //ȷ����һ������i
         for ( Rank j = i * i; j < n; j += i ) //����һϵ���ܱ�i������
            B.set( j ); // j���Ϊ������С��i*i�ĺ��������ڴ�֮ǰ�ѱ���ǣ�
   B.dump( file ); //��ɸѡ���ͳһ����ָ���ļ����Ա��պ�ֱ�ӵ���
}