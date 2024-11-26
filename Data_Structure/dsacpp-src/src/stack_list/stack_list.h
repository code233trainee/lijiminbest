/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

#include "List/List.h" //���б�Ϊ���࣬������ջģ����
template <typename T> class Stack: public List<T> { //���б�����/ĩ����Ϊջ��/��
public: //ԭ�нӿ�һ������
   void push ( T const& e ) { insertAsLast ( e ); } //��ջ����Ч�ڽ���Ԫ����Ϊ�б���ĩԪ�ز���
   T pop() { return remove ( last() ); } //��ջ����Ч��ɾ���б���ĩԪ��
   T& top() { return last()->data; } //ȡ����ֱ�ӷ����б���ĩԪ��
};