#ifndef __RADIX_SORT_H__
#define __RADIX_SORT_H__

#include "Assistance.h"				// ���������
template <class ElemType>
struct Node
{
       ElemType data;
       int next;
};


template <class ElemType>
void RadixSort (Node<ElemType> elem[], const int d, const int radix) {
// ��ʼ����: radixΪ����,dΪ�ؼ���λ��
// �������: ��elem����л�������
    int e[radix], f[radix], p, i, j, k, power;
    for (i = 0; i < d; i++) {      //��d �˷��䡢�ռ�
       for (j = 0; j < radix; j++)
           f[j] = 0;               //��ʼ�����������
       power = (int)pow((double)radix, i);
       p = elem[0].next;          //��ʼ����������ָ��
       while (p != -1) {           //�������Ԫ�ط���
           k = (elem[p].data / power) % radix;  //ȡ��ǰ����Ԫ�عؼ��ֵĵ� i λ 
           if (f[k] == 0)
               f[k] = p;           //ԭ����Ϊ��ʱ������Ԫ�������
           else                    //ԭ����ǿ�ʱ������Ԫ�����β
               elem[e[k]].next = p;
           e[k] = p;               //�޸���βָ��
           p = elem[p].next;      //ȡ��������һ�����
        }

        j = 0  ;                   //��ʼ�����ռ�
        while (f[j] == 0)          //�����ն���
            j++; 
        elem[0].next = f[j];    
        p = e[j];   
        for (k = j + 1; k < radix; k++)
            if (f[k] != 0) {       //����ÿ���ǿն�������
                elem[p].next = f[k]; 
                p = e[k];
            }
        elem[p].next = -1;

        cout << "����" << i << "λ����Ľ��:";
        for (p = elem[0].next; p != -1; p = elem[p].next)
            cout << elem[p].data << "   ";
        cout << endl; 
    }
}

#endif

