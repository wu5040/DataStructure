#ifndef __HEAP_SORT_H__
#define __HEAP_SORT_H__
#include "Assistance.h"				// ���������

template <class ElemType>
void FilterDown(ElemType elem[], int low, int high)
// �������:����lowΪ��������������Ϊһ������
{
    int f = low, i = 2 * low + 1;
    ElemType e = elem[low];
    while (i <= high) {			// fΪ���������,iΪf�������
		if (i < high && elem[i] < elem[i + 1])	
			i++;				// f���Һ��ӣ����Һ��ӵ�ֵ����, iָ���Һ���
		if (e < elem[i])	{	// ���ӵ�ֵ������˫�ף���������µ��� 
			elem[f] = elem[i];
            f = i;
            i = 2 * f + 1;
		}
		else 
            break;
	}
	elem[f] = e;
}

template <class ElemType>
void HeapSort(ElemType elem[], int n)
// �������:������elem���ж�����
{
	int i;
	for (i = (n-2)/2; i >= 0; --i) // ��ʼ���ѣ���elem[0 .. n - 1]����������
		FilterDown(elem, i, n - 1);
    cout << "��ʼ�ѣ�"; 
    Display(elem, n);			   // ��ʾ��ʼ�� 

	for (i = n - 1; i > 0; --i)	{  // ��i�˶�����
		Swap(elem[0], elem[i]);		
			// ���Ѷ�Ԫ�غ͵�ǰδ�������������elem[0 .. i]�����һ��Ԫ�ؽ���
		FilterDown(elem, 0, i - 1);	// ��elem[0 .. i - 1]���µ���Ϊ����
        cout << "��" << n - i << "�˶���������"; 
        Display(elem, n);			// ��ʾ�м��� 
	}
}

#endif

