#ifndef __INSERT_SORT_H__
#define __INSERT_SORT_H__
#include "Assistance.h"				// ���������

template <class ElemType>
struct Node
{
       ElemType data;
       int next;
};


template <class ElemType>
void LinkSelectionSort(Node<ElemType> elem[])
// �������:���þ�̬����elem�е�Ԫ�ؽ���ѡ������
{
    int p, q, pp, pq, h ;
    h = p = elem[0].next;
    elem[0].next = -1;   	// ���ó�ʼ���������ͷ 
    while ( p != -1 ) {
        q = pq = pp = p;  	//���ó�ʼ����ָ��
        p = elem[p].next;
        while (p != -1) { 	//ѡ����ǰ�����ؼ��ֵ�����Ԫ�أ�����qָ��
            if ( elem[p].data >= elem[q].data) {
                q = p ; 
                pq = pp ; 
            }
            pp = p ;
            p = elem[p].next;
       } 
       if ( h == q ) {   	//���ؼ��ֵ�����Ԫ���ڴ���������Ԫ������ı���
           h = elem[q].next;
           elem[q].next = elem[0].next;
           elem[0].next = q;
       } 
       else  {
           elem[pq].next = elem[q].next;
           elem[q].next = elem[0].next;
           elem[0].next = q;
          }
       p = h ;  //׼����һ��ѡ��
    }
}

#endif

