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
int LinkListMerge(Node<ElemType> elem[], int p, int q ) {
    // �鲢��p��qΪ����ͷָ����������� 
    int k = 0;   // kΪ��������ͷ���ָ��
    while (p !=-1 && q !=-1)
        if (elem[p].data <= elem[q].data) { 
            elem[k].next = p;
            k = p;
            p = elem[p].next; 
        }
        else {
            elem[k].next = q;
            k = q; 
            q = elem[q].next; 
        }
    if (p == -1)   
       elem[k].next = q; 
    else   
       elem[k].next = p;
    return elem[0].next;
}

template <class ElemType>
int LinkListMergeSort(Node<ElemType> elem[], int low, int high) {
    //��low~high���䣬���е�midΪ��, �ֱ����벿���Ұ벿���б�鲢������ٽ�����·�鲢
    if (low >= high)
        return low;
    int mid = (low + high) / 2, p, q;
    p = LinkListMergeSort(elem, low, mid);
    q = LinkListMergeSort(elem, mid+1, high);
    return LinkListMerge(elem, p, q);
}


#endif

