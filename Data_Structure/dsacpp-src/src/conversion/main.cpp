/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#include "convert.h"

/******************************************************************************************
 * ����ת��
 ******************************************************************************************/
int main() {
   srand((unsigned int)time(NULL)); //�������
   //srand( 31415926 ); //�̶����ӣ������ӣ������ã�
   unsigned long long n = 0;
   for ( int i = 0; i < 4; i++ ) {
      n <<= 16;
      n |= (rand() & 0x1) << 15 | rand();
   }
   int base = 2 + rand() % 14; //Ŀ����ƣ�2 ~ 16
   Stack<char> S; //��ջ��¼ת���õ��ĸ���λ
   ( 0 < n ) ? convert( S, n, base ) : S.push('0'); //����ת��
   printf( "\n\t%20llu_(10) = ", n );
   while ( !S.empty() ) printf ( "%c", ( S.pop() ) ); //�������ջ����λ������ȷ���
   printf( "_(%d)\a\n", base );
   return 0;
}