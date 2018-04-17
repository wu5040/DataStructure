#ifndef __SIMPLE_SELECT_SORT_H__
#define __SIMPLE_SELECT_SORT_H__

#include "Assistance.h"				// ���������

template <class ElemType>
void SimpleSelectionSort(ElemType elem[], int n)
// �������:������elem��n��Ԫ�ؽ��м�ѡ������
{
    int k; 
	for (int i = 0; i < n - 1; i++)	{	// ��i�˼�ѡ������
		k = i;			    			// k��¼elem[i .. n - 1]����СԪ��С��
		for (int j = i + 1; j < n; j++)
			if (elem[j] < elem[k])
				k = j;
	    if (k != i)
		    Swap(elem[i], elem[k]);		// ����elem[i], elem[k]
	    cout << "��ʾ��" << i + 1 << "�˼�ѡ������Ľ����"; 
        Display(elem, n);				// ��ʾ�м��� 
	}
}

#endif

